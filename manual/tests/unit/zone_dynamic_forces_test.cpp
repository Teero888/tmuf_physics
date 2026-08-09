#include "CHmsCorpus.hpp"
#include "CHmsDyna.hpp"
#include "CHmsForceFieldBall.hpp"
#include "CHmsForceFieldUniform.hpp"
#include "CHmsItem.hpp"
#include "CHmsZoneDynamic.hpp"
#include "CPlugPhysicalObject.hpp"

#include <cmath>
#include <cstdio>

class CSceneVehicleCarTuning;
CSceneVehicleCarTuning* g_tuning = nullptr;

namespace {

bool Near(float actual, float expected, float tolerance = 1.0e-6f) {
    return std::fabs(actual - expected) <= tolerance;
}

bool VecNear(
    const GmVec3& actual,
    const GmVec3& expected,
    float tolerance = 1.0e-6f) {
    return Near(actual.x, expected.x, tolerance) &&
           Near(actual.y, expected.y, tolerance) &&
           Near(actual.z, expected.z, tolerance);
}

bool Expect(const char* label, bool condition) {
    if (!condition) std::fprintf(stderr, "%s: FAIL\n", label);
    return condition;
}

class RecordingPhysicsCallback final : public CHmsItem::CCallback {
public:
    int calls = 0;
    float lastDt = 0.0f;
    GmVec3 forceToAdd{1.0f, -2.0f, 0.5f};

    ECallback GetType() const override { return CB_PHYSICS; }

    void ComputeForces(CHmsItem* item, float dt) override {
        ++calls;
        lastDt = dt;
        item->AddForce(item, &forceToAdd, nullptr);
    }
};

bool TestNativeFieldImplementations() {
    bool passed = true;
    CHmsForceFieldUniform uniform;
    GmVec3 value(123.0f, 456.0f, 789.0f);
    passed &= Expect(
        "uniform field is inactive after native construction",
        !uniform.GetValue(GmVec3(10.0f, 20.0f, 30.0f), value));
    uniform.m_isActive = 1;
    passed &= Expect(
        "uniform field exposes exact constructor gravity",
        uniform.GetValue(GmVec3(10.0f, 20.0f, 30.0f), value) &&
        VecNear(value, GmVec3(0.0f, -9.81000041961669921875f, 0.0f)));

    CHmsForceFieldBall ball;
    passed &= Expect(
        "ball field applies inverse-square radial value",
        ball.GetValue(GmVec3(1.0f, 0.0f, 0.0f), value) &&
        VecNear(value, GmVec3(1.0f, 0.0f, 0.0f)));
    passed &= Expect(
        "ball field excludes its radius boundary",
        !ball.GetValue(GmVec3(2.0f, 0.0f, 0.0f), value));
    passed &= Expect(
        "ball field excludes its singular center",
        !ball.GetValue(GmVec3(0.0f, 0.0f, 0.0f), value));
    return passed;
}

bool TestComputeCorpusForcesLifecycle() {
    bool passed = true;
    CPlugPhysicalObject physical;
    physical.m_mass = 2.0f;
    physical.m_forceFieldCoef = 3.0f;
    physical.m_linearDamping = 0.25f;
    physical.m_angularDampingX = 0.5f;
    physical.m_inverseInertia.SetIdentity();

    CHmsItem item;
    CHmsCorpus* corpus = new CHmsCorpus();
    corpus->m_item = &item;
    corpus->m_dyna = new CHmsDyna();
    item.m_corpuses.Add(corpus);
    CHmsDyna& dyna = *corpus->m_dyna;
    dyna.m_field_0x108 = &physical;
    dyna.m_dynamicType = 1;
    dyna.UpdateWorldInverseInertia();
    dyna.CurrentState().m_linearSpeed = GmVec3(4.0f, -2.0f, 1.0f);
    dyna.CurrentState().m_angularSpeed = GmVec3(2.0f, -4.0f, 1.0f);
    dyna.Force() = GmVec3(99.0f, 98.0f, 97.0f);
    dyna.Torque() = GmVec3(96.0f, 95.0f, 94.0f);

    CHmsForceFieldUniform field;
    field.m_isActive = 1;
    field.m_force[0] = 1.0f;
    field.m_force[1] = 2.0f;
    field.m_force[2] = 3.0f;
    RecordingPhysicsCallback callback;
    item.CallbackSet(CB_PHYSICS, &callback);

    CHmsZoneDynamic zone;
    zone.m_dynamicCorpuses.Add(corpus);
    zone.AddForceField(&field);
    zone.PrepareForPhysicsStep(0.02f);

    // Field: (1,2,3) * mass 2 * coefficient 3.
    // Damping: (4,-2,1) * -0.25. Callback then adds (1,-2,0.5).
    passed &= Expect(
        "force fields, damping and callback use native ordering",
        VecNear(dyna.Force(), GmVec3(6.0f, 10.5f, 18.25f)));
    passed &= Expect(
        "angular damping replaces torque for a full dynamic body",
        VecNear(dyna.Torque(), GmVec3(-1.0f, 2.0f, -0.5f)));
    passed &= Expect(
        "dynamic state is validated before force replacement",
        VecNear(
            dyna.ValidatedState().m_force,
            GmVec3(99.0f, 98.0f, 97.0f)) &&
        VecNear(
            dyna.ValidatedState().m_torque,
            GmVec3(96.0f, 95.0f, 94.0f)));
    passed &= Expect(
        "physics callback receives the force-step duration",
        callback.calls == 1 && Near(callback.lastDt, 0.02f));

    dyna.Force() = GmVec3(-1000.0f, -1000.0f, -1000.0f);
    zone.PrepareForPhysicsStep(0.02f);
    passed &= Expect(
        "force preparation resets rather than accumulates frames",
        VecNear(dyna.Force(), GmVec3(6.0f, 10.5f, 18.25f)) &&
        callback.calls == 2);

    item.m_flags1 |= 0x100000u;
    zone.PrepareForPhysicsStep(0.02f);
    passed &= Expect(
        "native no-force flag zeros force and torque and skips callback",
        VecNear(dyna.Force(), GmVec3(0.0f, 0.0f, 0.0f)) &&
        VecNear(dyna.Torque(), GmVec3(0.0f, 0.0f, 0.0f)) &&
        callback.calls == 2);
    item.m_flags1 &= ~0x100000u;

    zone.PrepareForPhysicsStep(0.02f);
    GmVec3 adapterForce(10.0f, 0.0f, 0.0f);
    dyna.AddForce(nullptr, &adapterForce, nullptr);
    const int preparedCallbackCount = callback.calls;
    zone.PhysicsStep2(0.02f);
    passed &= Expect(
        "prepared adapter force is not erased by PhysicsStep2",
        callback.calls == preparedCallbackCount &&
        VecNear(dyna.Force(), GmVec3(16.0f, 10.5f, 18.25f)));

    zone.PhysicsStep2(0.02f);
    passed &= Expect(
        "ordinary PhysicsStep2 prepares the following frame itself",
        callback.calls == preparedCallbackCount + 1);
    return passed;
}

} // namespace

int main() {
    const bool passed = TestNativeFieldImplementations() &&
        TestComputeCorpusForcesLifecycle();
    if (!passed) return 1;
    std::puts("zone dynamic force lifecycle regression: PASS");
    return 0;
}
