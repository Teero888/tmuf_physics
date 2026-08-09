#include <cmath>
#include "CHmsDyna.hpp"
#include "CClassicBufferMemory.hpp"
#include "CSceneVehicleCarTuning.hpp"
#include "CPlugPhysicalObject.hpp"
#include "GmArchive.hpp"
#include <cstdio>

extern CSceneVehicleCarTuning* g_tuning;

namespace {

const GmVec3 kZeroVec3(0.0f, 0.0f, 0.0f);

GmVec3 TransformVector(const GmMat3& matrix, const GmVec3& vector) {
    return GmVec3{
        matrix.m00 * vector.x + matrix.m01 * vector.y + matrix.m02 * vector.z,
        matrix.m10 * vector.x + matrix.m11 * vector.y + matrix.m12 * vector.z,
        matrix.m20 * vector.x + matrix.m21 * vector.y + matrix.m22 * vector.z,
    };
}

GmVec3 TransformVectorTranspose(
    const GmMat3& matrix, const GmVec3& vector) {
    return GmVec3{
        matrix.m00 * vector.x + matrix.m10 * vector.y + matrix.m20 * vector.z,
        matrix.m01 * vector.x + matrix.m11 * vector.y + matrix.m21 * vector.z,
        matrix.m02 * vector.x + matrix.m12 * vector.y + matrix.m22 * vector.z,
    };
}

void SetWorldInverseInertia(
    CHmsDyna::CHmsStateDyna& state, const GmMat3& localInverseInertia) {
    // Native GmMat3::Mult left-multiplies the stored value. Starting from
    // R^T therefore produces R * I_local^-1 * R^T after these two calls.
    state.m_worldInverseInertia.SetTranspose(state.m_rotationMatrix);
    state.m_worldInverseInertia.Mult(localInverseInertia);
    state.m_worldInverseInertia.Mult(state.m_rotationMatrix);
}

void SetStateYaw(CHmsDyna::CHmsStateDyna& state, float yaw) {
    const float cosine = std::cos(yaw);
    const float sine = std::sin(yaw);
    state.m_rotationMatrix.SetIdentity();
    state.m_rotationMatrix.m00 = cosine;
    state.m_rotationMatrix.m02 = sine;
    state.m_rotationMatrix.m20 = -sine;
    state.m_rotationMatrix.m22 = cosine;
    state.m_rotation.Set(state.m_rotationMatrix);
}

void SetStateLocation(
    CHmsDyna::CHmsStateDyna& state, const GmIso4& location) {
    state.m_rotationMatrix = location.rot;
    state.m_rotation.Set(state.m_rotationMatrix);
    state.m_position = GmVec3(location.tX, location.tY, location.tZ);
}

} // namespace

void CHmsDyna::CHmsStateDyna::Initialize() {
    m_rotation.SetIdentity();
    m_rotationMatrix.SetIdentity();
    m_position = kZeroVec3;
    m_worldInverseInertia.SetIdentity();
    m_owner32 = 0;
    Reset(nullptr);
}

void CHmsDyna::CHmsStateDyna::Reset(GmFrustumIso4* param_1) {
    (void)param_1;
    m_linearSpeed = kZeroVec3;
    m_additionalLinearSpeed = kZeroVec3;
    m_angularSpeed = kZeroVec3;
    m_force = kZeroVec3;
    m_torque = kZeroVec3;
    m_hasSavedLinearSpeed = 0;
    m_savedLinearSpeed = kZeroVec3;
}

void CHmsDyna::CHmsStateDyna::RestoreState(
    CClassicBufferMemory* buffer, uint8_t quality) {
    if (buffer == nullptr) return;
    if (quality == 0u) {
        GmArchive::ReadVec3Pos_9(buffer, &m_position);
        GmArchive::ReadQuat_6(buffer, &m_rotation);
        m_rotationMatrix.Set(m_rotation);
        return;
    }
    if (quality == 1u) {
        GmArchive::ReadVec3Pos_12(buffer, &m_position);
        GmArchive::ReadQuat_6(buffer, &m_rotation);
        m_rotationMatrix.Set(m_rotation);
        GmArchive::ReadVec3_4(buffer, &m_linearSpeed);
        GmArchive::ReadVec3_4(buffer, &m_angularSpeed);
    }
}

CHmsDyna::CHmsDyna()
    : m_field_0x4(0),
      m_field_0x8(0),
      m_field_0xc0(0),
      m_field_0xc4(10000.0f),
      m_field_0x108(nullptr),
      m_validatedState(&m_validatedStateStorage),
      m_currentState(&m_currentStateStorage),
      m_field_0x33c(1),
      m_dynamicType(0) {
    m_asyncState.Initialize();
    m_validatedStateStorage.Initialize();
    m_currentStateStorage.Initialize();
    m_tempState.Initialize();
}

CHmsDyna::~CHmsDyna() {}

float CHmsDyna::GetMass() const {
    if (m_field_0x108 != nullptr && m_field_0x108->m_mass > 0.0f) {
        return m_field_0x108->m_mass;
    }
    return g_tuning != nullptr && g_tuning->m_mass > 0.0f
        ? g_tuning->m_mass
        : 1.0f;
}

GmVec3 CHmsDyna::GetCenterOfMassWorld() const {
    if (m_field_0x108 == nullptr) return m_currentState->m_position;
    return m_currentState->m_position + TransformVector(
        m_currentState->m_rotationMatrix,
        m_field_0x108->m_centerOfMass);
}

void CHmsDyna::UpdateWorldInverseInertia() {
    if (m_field_0x108 == nullptr) return;
    SetWorldInverseInertia(
        *m_currentState, m_field_0x108->m_inverseInertia);
    SetWorldInverseInertia(
        *m_validatedState, m_field_0x108->m_inverseInertia);
}

void CHmsDyna::GetLocalLinearSpeed(GmVec3* param_2) {
    if (param_2 != nullptr) {
        *param_2 = TransformVectorTranspose(
            m_currentState->m_rotationMatrix,
            m_currentState->m_linearSpeed);
    }
}

void CHmsDyna::GetSpeed(const GmVec3* point, GmVec3* speed) {
    if (speed == nullptr) return;
    if (m_dynamicType == 2) {
        *speed = kZeroVec3;
        return;
    }

    *speed = m_currentState->m_linearSpeed;
    if (m_dynamicType == 1 && point != nullptr) {
        const GmVec3 lever = *point - GetCenterOfMassWorld();
        *speed += GmVec3::Cross(m_currentState->m_angularSpeed, lever);
    }
}

void CHmsDyna::GetLinearSpeed(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) *param_2 = m_currentState->m_linearSpeed;
}

void CHmsDyna::GetAngularSpeed(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) *param_2 = m_currentState->m_angularSpeed;
}

void CHmsDyna::GetForce(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) *param_2 = m_currentState->m_force;
}

void CHmsDyna::SetLinearSpeed(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) m_currentState->m_linearSpeed = *param_2;
}

void CHmsDyna::SetAngularSpeed(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) m_currentState->m_angularSpeed = *param_2;
}

void CHmsDyna::SetForce(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) m_currentState->m_force = *param_2;
}

void CHmsDyna::SetTorque(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) m_currentState->m_torque = *param_2;
}

void CHmsDyna::SetTranslation(GmIso4* param_1, GmVec3* param_2) {
    GmVec3 position;
    if (param_2 != nullptr) {
        position = *param_2;
    } else if (param_1 != nullptr) {
        position = GmVec3(param_1->tX, param_1->tY, param_1->tZ);
    } else return;
    m_currentState->m_position = position;
    m_validatedState->m_position = position;
}

void CHmsDyna::AddForce(
    CHmsItem* param_1, GmVec3* param_2, GmVec3* param_3) {
    if (param_2 != nullptr) m_currentState->m_force += *param_2;
}

void CHmsDyna::AddImpulse(CHmsItem* param_1, GmVec3* param_2) {
    (void)param_1;
    if (param_2 == nullptr || m_dynamicType == 2) return;
    m_field_0x33c = 1;
    const float mass = GetMass();
    m_currentState->m_linearSpeed += *param_2 / mass;
}

void CHmsDyna::AddImpulseAtPoint(
    const GmVec3* impulse, const GmVec3* point) {
    if (impulse == nullptr || m_dynamicType == 2) return;
    AddImpulse(nullptr, const_cast<GmVec3*>(impulse));
    if (m_dynamicType != 1 || point == nullptr) return;

    const GmVec3 lever = *point - GetCenterOfMassWorld();
    const GmVec3 angularImpulse = GmVec3::Cross(lever, *impulse);
    m_currentState->m_angularSpeed += TransformVector(
        m_currentState->m_worldInverseInertia, angularImpulse);
}

void CHmsDyna::AddTorque(CHmsItem* param_1, GmVec3* param_2) {
    if (param_2 != nullptr) m_currentState->m_torque += *param_2;
}

void CHmsDyna::AddLocalImpulse(GmVec3* param_2) {
    if (param_2 == nullptr) return;
    GmVec3 worldImpulse = TransformVector(
        m_currentState->m_rotationMatrix, *param_2);
    AddImpulse(nullptr, &worldImpulse);
}
void CHmsDyna::AddReplacement(GmVec3* param_2) {
    if (param_2 == nullptr) return;
    if (m_field_0x33c == 0) m_field_0x33c = 1;
    m_replacements.Add(*param_2);
}
void CHmsDyna::AddLocalTorque(GmVec3* param_2) {
    if (param_2 == nullptr) return;
    m_currentState->m_torque += TransformVector(
        m_currentState->m_rotationMatrix, *param_2);
}
void CHmsDyna::GetLocalAngularSpeed(GmVec3* param_2) {
    if (param_2 != nullptr) {
        *param_2 = TransformVectorTranspose(
            m_currentState->m_rotationMatrix,
            m_currentState->m_angularSpeed);
    }
}
void CHmsDyna::SetLocalAngularSpeed(GmVec3* param_2) {
    if (param_2 != nullptr) {
        m_currentState->m_angularSpeed = TransformVector(
            m_currentState->m_rotationMatrix, *param_2);
    }
}
void CHmsDyna::SetLocalLinearSpeed(GmVec3* param_2) {
    if (param_2 != nullptr) {
        m_currentState->m_linearSpeed = TransformVector(
            m_currentState->m_rotationMatrix, *param_2);
    }
}
void CHmsDyna::SetLocalTorque(GmVec3* param_2) {
    if (param_2 != nullptr) {
        m_currentState->m_torque = TransformVector(
            m_currentState->m_rotationMatrix, *param_2);
    }
}

int CHmsDyna::IsStateDifferentFrom(CHmsItem* param_1, GmIso4* param_2) {
    const GmIso4* location = param_2 != nullptr
        ? param_2
        : reinterpret_cast<const GmIso4*>(param_1);
    if (location == nullptr) return 1;
    constexpr float kStateDifferenceThreshold = 1.0e-5f;
    const GmVec3 translationDifference{
        location->tX - m_validatedState->m_position.x,
        location->tY - m_validatedState->m_position.y,
        location->tZ - m_validatedState->m_position.z,
    };
    if (GmVec3::Dot(translationDifference, translationDifference) >
        kStateDifferenceThreshold) {
        return 1;
    }

    const float* locationRotation =
        reinterpret_cast<const float*>(&location->rot);
    const float* validatedRotation =
        reinterpret_cast<const float*>(&m_validatedState->m_rotationMatrix);
    for (int row = 0; row < 3; ++row) {
        const GmVec3 difference{
            locationRotation[row * 3] - validatedRotation[row * 3],
            locationRotation[row * 3 + 1] - validatedRotation[row * 3 + 1],
            locationRotation[row * 3 + 2] - validatedRotation[row * 3 + 2],
        };
        if (GmVec3::Dot(difference, difference) >
            kStateDifferenceThreshold) {
            return 1;
        }
    }
    return 0;
}
void CHmsDyna::AddStateForPrediction(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, uint32_t param_3, uint32_t param_4) {}
void CHmsDyna::SaveState(
    CSceneToyBoat* param_1, CClassicBufferMemory* param_2,
    uint32_t* param_3, uint32_t param_4) {
    (void)param_3;
    (void)param_4;
    CClassicBufferMemory* buffer =
        reinterpret_cast<CClassicBufferMemory*>(param_1);
    if (buffer == nullptr) return;
    const uintptr_t quality = reinterpret_cast<uintptr_t>(param_2);
    const CHmsStateDyna& state = *m_validatedState;
    if (quality == 0u) {
        GmArchive::WriteVec3Pos_9(buffer, &state.m_position);
        GmArchive::WriteQuat_6(buffer, &state.m_rotation);
        return;
    }
    if (quality == 1u) {
        GmArchive::WriteVec3Pos_12(buffer, &state.m_position);
        GmArchive::WriteQuat_6(buffer, &state.m_rotation);
        // HmsZoneDynamic::UseSavedLinearSpeed defaults to one in the fixed
        // executable (DAT_00cdc700). Preserve that default here.
        const GmVec3& linearSpeed = state.m_hasSavedLinearSpeed != 0u
            ? state.m_savedLinearSpeed
            : state.m_linearSpeed;
        GmArchive::WriteVec3_4(buffer, &linearSpeed);
        GmArchive::WriteVec3_4(buffer, &state.m_angularSpeed);
    }
}
void CHmsDyna::Reset(GmFrustumIso4* param_1) {
    m_validatedStateStorage.Reset(param_1);
    m_currentStateStorage.Reset(param_1);
    m_validatedState = &m_validatedStateStorage;
    m_currentState = &m_currentStateStorage;
    m_replacements.m_count = 0;
    m_field_0x4 = 0;
    m_field_0x8 = 0;
    m_asyncState.Reset(param_1);
}
void CHmsDyna::OldRestoreStaticState(CHmsCorpus* param_1, CClassicBufferMemory* param_2, int param_3, uint8_t param_4, int param_5) {}
void CHmsDyna::RestoreStaticState(
    CSceneToyBoat* param_1, CClassicBufferMemory* param_2, int param_3,
    uint32_t param_4, uint32_t param_5, int param_6) {
    (void)param_4;
    (void)param_5;
    (void)param_6;
    CClassicBufferMemory* buffer =
        reinterpret_cast<CClassicBufferMemory*>(param_1);
    CHmsStateDyna* state = param_2 != nullptr
        ? m_validatedState
        : m_currentState;
    state->RestoreState(buffer, static_cast<uint8_t>(param_3));
}
void CHmsDyna::RotateOf(CHmsCorpus* param_1, GmMat3* param_2) {
    const GmMat3* rotation = param_2 != nullptr
        ? param_2
        : reinterpret_cast<const GmMat3*>(param_1);
    if (rotation == nullptr) return;
    GmIso4 location;
    location.rot.SetMult(*rotation, m_currentState->m_rotationMatrix);
    location.rot.OrthoNormalize();
    location.SetTranslation(m_currentState->m_position);
    SetLocation(nullptr, &location);
}
void CHmsDyna::SetDynamicType(CHmsItem* param_1, int param_2) {
    (void)param_2;
    m_dynamicType = static_cast<int>(reinterpret_cast<uintptr_t>(param_1));
    m_validatedState->m_angularSpeed = kZeroVec3;
    m_currentState->m_angularSpeed = kZeroVec3;
    m_validatedState->m_torque = kZeroVec3;
    m_currentState->m_torque = kZeroVec3;
}
void CHmsDyna::SetLocation(CPlugTree* param_1, GmIso4* param_2) {
    if (param_2 == nullptr) return;
    SetStateLocation(*m_validatedState, *param_2);
    SetStateLocation(*m_currentState, *param_2);
    UpdateWorldInverseInertia();
}

float CHmsDyna::GetYaw() const {
    return std::atan2(
        m_currentState->m_rotationMatrix.m02,
        m_currentState->m_rotationMatrix.m22);
}

void CHmsDyna::SetYaw(float yaw) {
    SetStateYaw(*m_validatedState, yaw);
    SetStateYaw(*m_currentState, yaw);
    UpdateWorldInverseInertia();
}

void CHmsDyna::Integrate(float dt) {
    // Standalone compatibility entry point. Native simulation uses these same
    // pre/post boundaries around collision response.
    DoPreCollisionDynamic(dt);
}

void CHmsDyna::Move(float dt) {
    (void)dt;
    DoPostCollisionDynamic();
}

// In CHmsItem, we need to map to these globals for the simple manual test:
// Wait, actually CHmsItem AddForce maps to AddLocalForce here
void CHmsDyna::AddLocalForce(GmVec3* param_2) {
    if (param_2 == nullptr) return;
    m_currentState->m_force += TransformVector(
        m_currentState->m_rotationMatrix, *param_2);
}

void CHmsDyna::GetLocalForce(GmVec3* param_2) {
    if (param_2 != nullptr) {
        *param_2 = TransformVectorTranspose(
            m_currentState->m_rotationMatrix,
            m_currentState->m_force);
    }
}

void CHmsDyna::SetLocalForce(GmVec3* param_2) {
    if (param_2 != nullptr) {
        m_currentState->m_force = TransformVector(
            m_currentState->m_rotationMatrix, *param_2);
    }
}

void CHmsDyna::CopyStateToTemp() {
    m_tempState = *m_currentState;
}

void CHmsDyna::CopyTempToState() {
    *m_validatedState = m_tempState;
}

void CHmsDyna::ApplyReplacement(GmVec3* replacement) {
    if (replacement != nullptr) m_currentState->m_position += *replacement;
}

void CHmsDyna::ComputeSynthetizedReplacement(GmVec3* output) {
    if (output == nullptr) return;
    if (m_replacements.IsEmpty()) {
        *output = kZeroVec3;
        return;
    }

    GmVec3 result = m_replacements[0];
    constexpr float kDirectionThreshold = 9.999999439624929e-11f;
    for (uint32_t i = 1; i < m_replacements.GetCount(); ++i) {
        const GmVec3& replacement = m_replacements[i];
        const float dot = GmVec3::Dot(result, replacement);
        if (dot > 0.0f) {
            const float resultLengthSq = GmVec3::Dot(result, result);
            if (resultLengthSq > kDirectionThreshold) {
                const float retainedProjection =
                    std::min(dot, resultLengthSq) / resultLengthSq;
                result -= result * retainedProjection;
            }
        }
        result += replacement;
    }

    constexpr float kReplacementSkin = 0.01f;
    const float resultLengthSq = GmVec3::Dot(result, result);
    if (resultLengthSq <= kReplacementSkin * kReplacementSkin) {
        *output = kZeroVec3;
        return;
    }
    *output = result *
        (1.0f - kReplacementSkin / std::sqrt(resultLengthSq));
}

void CHmsDyna::ValidateDynamicState() {
    *m_validatedState = *m_currentState;
}

void CHmsDyna::IntegrateStep(
    CHmsStateDyna* input, CHmsStateDyna* output, float dt) {
    if (input == nullptr || output == nullptr) return;
    if (m_dynamicType == 2) {
        *output = *input;
        return;
    }

    output->m_position = input->m_position +
        (input->m_linearSpeed + input->m_additionalLinearSpeed) * dt;
    output->m_additionalLinearSpeed = kZeroVec3;

    const float mass = GetMass();
    output->m_linearSpeed =
        input->m_linearSpeed + input->m_force * (dt / mass);
    if (m_dynamicType == 0) {
        // The static/translation-only path copies only the matrix. The native
        // routine leaves every other unwritten output field untouched.
        output->m_rotationMatrix = input->m_rotationMatrix;
        return;
    }

    const GmVec3 angularAcceleration = TransformVector(
        input->m_worldInverseInertia, input->m_torque);
    constexpr float kAngularMotionThreshold =
        9.999999439624929e-11f;
    if (GmVec3::Dot(input->m_angularSpeed, input->m_angularSpeed) <=
        kAngularMotionThreshold) {
        output->m_rotation = input->m_rotation;
        output->m_rotationMatrix = input->m_rotationMatrix;
    } else {
        // 0x53368F forms 0.5 * ([0, omega] * q). Angular speed is in
        // world space, so the velocity quaternion is on the left.
        const double w = input->m_rotation.w;
        const double x = input->m_rotation.x;
        const double y = input->m_rotation.y;
        const double z = input->m_rotation.z;
        const double wx = input->m_angularSpeed.x;
        const double wy = input->m_angularSpeed.y;
        const double wz = input->m_angularSpeed.z;
        const float derivativeW = static_cast<float>(
            ((-wx * x - wy * y) - wz * z) * 0.5);
        const float derivativeX = static_cast<float>(
            ((w * wx + wy * z) - wz * y) * 0.5);
        const float derivativeY = static_cast<float>(
            ((w * wy - wx * z) + wz * x) * 0.5);
        const float derivativeZ = static_cast<float>(
            ((w * wz + wx * y) - wy * x) * 0.5);

        output->m_rotation = input->m_rotation;
        output->m_rotation.w = static_cast<float>(
            input->m_rotation.w + static_cast<double>(dt) * derivativeW);
        output->m_rotation.x = static_cast<float>(
            input->m_rotation.x + static_cast<double>(dt) * derivativeX);
        output->m_rotation.y = static_cast<float>(
            input->m_rotation.y + static_cast<double>(dt) * derivativeY);
        output->m_rotation.z = static_cast<float>(
            input->m_rotation.z + static_cast<double>(dt) * derivativeZ);
        output->m_rotation.Normalize();
        output->m_rotationMatrix.Set(output->m_rotation);

        if (m_field_0x108 != nullptr) {
            const GmVec3 oldCenterOffset = TransformVector(
                input->m_rotationMatrix,
                m_field_0x108->m_centerOfMass);
            const GmVec3 newCenterOffset = TransformVector(
                output->m_rotationMatrix,
                m_field_0x108->m_centerOfMass);
            output->m_position -= newCenterOffset - oldCenterOffset;
        }
    }

    output->m_angularSpeed =
        input->m_angularSpeed + angularAcceleration * dt;
    if (m_field_0xc0 != 0) {
        const float angularSpeedSq = GmVec3::Dot(
            output->m_angularSpeed, output->m_angularSpeed);
        if (m_field_0xc4 * m_field_0xc4 < angularSpeedSq) {
            output->m_angularSpeed *=
                m_field_0xc4 / std::sqrt(angularSpeedSq);
        }
    }

    if (m_field_0x108 != nullptr) {
        SetWorldInverseInertia(
            *output, m_field_0x108->m_inverseInertia);
    }
}

void CHmsDyna::DoPreCollisionDynamic(float dt) {
    CHmsStateDyna input = *m_currentState;
    IntegrateStep(&input, m_currentState, dt);
    m_replacements.m_count = 0;
}

void CHmsDyna::DoPostCollisionDynamic() {
    GmVec3 replacement;
    ComputeSynthetizedReplacement(&replacement);
    ApplyReplacement(&replacement);
}
