#include "Gm/GmSurf.hpp"
#include "Plug/CPlugSolid.hpp"
#include "Plug/CPlugSurface.hpp"
#include "Plug/CPlugSurfaceGeom.hpp"
#include "Plug/CPlugTree.hpp"
#include "Track/TrackMapLoader.hpp"
#include "Track/VehicleAssetLoader.hpp"

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class CSceneVehicleCarTuning;
CSceneVehicleCarTuning* g_tuning = nullptr;

namespace {

bool Near(float actual, float expected, float tolerance = 1e-6f) {
    if (std::abs(actual - expected) <= tolerance) return true;
    std::cerr << "expected " << expected << ", got " << actual << '\n';
    return false;
}

uint64_t HashMeshVertices(const GmSurfMesh& mesh) {
    // FNV-1a over the exact IEEE-754 coordinate bytes written by the
    // extractor. Counts alone cannot detect a whole rotated block footprint
    // being translated by one or more 32 m cells.
    uint64_t hash = 14695981039346656037ull;
    for (uint32_t index = 0; index < mesh.m_vertices.GetCount(); ++index) {
        const auto* bytes = reinterpret_cast<const uint8_t*>(&mesh.m_vertices[index]);
        for (std::size_t byte = 0; byte < sizeof(GmVec3); ++byte) {
            hash ^= bytes[byte];
            hash *= 1099511628211ull;
        }
    }
    return hash;
}

template <typename T>
void Write(std::ofstream& file, const T& value) {
    file.write(reinterpret_cast<const char*>(&value), sizeof(value));
}

bool WriteFixture(const std::string& path) {
    std::ofstream file(path, std::ios::binary);
    if (!file.is_open()) return false;
    file.write("TMNFCOL1", 8);
    const uint32_t vertexCount = 3;
    const uint32_t triangleCount = 1;
    const uint32_t blockCount = 1;
    const uint32_t reserved = 0;
    Write(file, vertexCount);
    Write(file, triangleCount);
    Write(file, blockCount);
    Write(file, reserved);

    // Winding gives an exact +Y plane normal.
    const GmVec3 vertices[] = {
        GmVec3(0.0f, 0.0f, 0.0f),
        GmVec3(0.0f, 0.0f, 1.0f),
        GmVec3(1.0f, 0.0f, 0.0f),
    };
    for (const GmVec3& vertex : vertices) {
        Write(file, vertex.x);
        Write(file, vertex.y);
        Write(file, vertex.z);
    }

    const uint32_t indices[] = {0, 1, 2};
    const GmVec3 normal(0.0f, 1.0f, 0.0f);
    const float planeDistance = 0.0f;
    const uint16_t material = 16; // Asphalt
    const uint16_t padding = 0;
    for (uint32_t index : indices) Write(file, index);
    Write(file, normal.x);
    Write(file, normal.y);
    Write(file, normal.z);
    Write(file, planeDistance);
    Write(file, material);
    Write(file, padding);
    return static_cast<bool>(file);
}

bool WriteVehicleFixture(const std::string& path) {
    std::ofstream file(path, std::ios::binary);
    if (!file.is_open()) return false;
    file.write("TMNFVEH1", 8);
    const uint32_t primitiveCount = 1u;
    const uint32_t reserved = 0u;
    const uint32_t type = 1u;
    const uint16_t material = 16u;
    const uint16_t flags = 0u;
    const GmVec3 radii(0.5f, 0.75f, 1.25f);
    GmIso4 location;
    location.SetIdentity();
    location.tX = 1.0f;
    location.tY = 2.0f;
    location.tZ = 3.0f;
    Write(file, primitiveCount);
    Write(file, reserved);
    Write(file, type);
    Write(file, material);
    Write(file, flags);
    Write(file, radii);
    Write(file, location);
    return static_cast<bool>(file);
}

} // namespace

int main(int argc, char** argv) {
    const std::string fixturePath = "/tmp/tmnf_track_collision_test.tmnfcol";
    if (!WriteFixture(fixturePath)) {
        std::cerr << "could not write collision fixture\n";
        return 1;
    }

    GmSurfMesh mesh;
    TrackMapLoadResult fixtureResult;
    bool passed = LoadTrackMapCollision(
        mesh, fixturePath, TrackMapLoadOptions{}, &fixtureResult);
    std::remove(fixturePath.c_str());
    passed &= mesh.m_vertices.GetCount() == 3;
    passed &= mesh.m_triangles.GetCount() == 1;
    passed &= fixtureResult.cacheHit;
    passed &= !fixtureResult.sourceWasChallengeGbx;

    GmIso4 identity;
    identity.SetIdentity();
    const GmVec3 rayPosition(0.25f, 1.0f, 0.25f);
    const GmVec3 rayDirection(0.0f, -2.0f, 0.0f);
    float hitT = 1.0f;
    GmVec3 hitNormal;
    passed &= mesh.ClipSegment2(
        rayPosition, rayDirection, identity, hitT, hitNormal) != 0;
    passed &= Near(hitT, 0.5f);
    passed &= Near(hitNormal.x, 0.0f);
    passed &= Near(hitNormal.y, 1.0f);
    passed &= Near(hitNormal.z, 0.0f);

    hitT = 1.0f;
    uint16_t material = 0xffff;
    passed &= mesh.ClipSegment3(
        rayPosition, rayDirection, identity, hitT, material) != 0;
    passed &= material == 16;
    std::vector<uint32_t> candidates;
    passed &= mesh.GetAabbCandidates(
        0.2f, 0.2f, 0.3f, 0.3f, candidates);
    passed &= candidates.size() == 1u && candidates[0] == 0u;
    passed &= mesh.GetAabbCandidates(
        100.0f, 100.0f, 101.0f, 101.0f, candidates);
    passed &= candidates.empty();

    const std::string vehicleFixturePath =
        "/tmp/tmnf_vehicle_collision_test.tmnfveh";
    passed &= WriteVehicleFixture(vehicleFixturePath);
    StadiumVehicleAsset vehicleFixture;
    std::string vehicleFixtureError;
    passed &= vehicleFixture.LoadCollision(
        vehicleFixturePath, &vehicleFixtureError);
    std::remove(vehicleFixturePath.c_str());
    CPlugSolid* fixtureSolid = vehicleFixture.CollisionSolid();
    CPlugTree* fixtureRoot = fixtureSolid != nullptr
        ? fixtureSolid->m_tree : nullptr;
    passed &= fixtureRoot != nullptr && fixtureRoot->GetChildCount() == 1u;
    CPlugTree* fixturePrimitive = fixtureRoot != nullptr
        ? fixtureRoot->GetChild(0u) : nullptr;
    GmSurf* fixtureSurface = fixturePrimitive != nullptr &&
        fixturePrimitive->m_surface != nullptr &&
        fixturePrimitive->m_surface->m_geometry != nullptr
        ? fixturePrimitive->m_surface->m_geometry->GetGmSurf() : nullptr;
    passed &= fixtureSurface != nullptr && fixtureSurface->m_type == 1u;
    if (fixtureSurface != nullptr && fixtureSurface->m_type == 1u) {
        const auto* ellipsoid =
            static_cast<const GmSurfEllipsoid*>(fixtureSurface);
        passed &= Near(ellipsoid->m_radii.x, 0.5f);
        passed &= Near(ellipsoid->m_radii.y, 0.75f);
        passed &= Near(ellipsoid->m_radii.z, 1.25f);
    }
    passed &= fixturePrimitive != nullptr &&
        Near(fixturePrimitive->m_location.tX, 1.0f) &&
        Near(fixturePrimitive->m_location.tY, 2.0f) &&
        Near(fixturePrimitive->m_location.tZ, 3.0f);

    if (argc != 1 && argc != 4) {
        std::cerr << "Usage: " << argv[0]
                  << " [A01-Race.Challenge.Gbx PacksDirectory "
                     "TrackCollisionExtractor.csproj]\n";
        return 2;
    }

    if (argc == 4) {
        GmSurfMesh a01;
        GmSurfMesh stadiumDecoration;
        TrackMapLoadOptions options;
        options.packsDirectory = argv[2];
        options.extractorProject = argv[3];
        TrackMapLoadResult a01Result;
        passed &= LoadTrackMapCollision(
            a01, argv[1], options, &a01Result, &stadiumDecoration);
        passed &= a01Result.sourceWasChallengeGbx;
        passed &= a01Result.mapName == "A01-Race";
        passed &= a01Result.mapAuthor == "Nadeo";
        passed &= a01Result.environment == "Stadium";
        passed &= a01Result.blockCount == 397;
        passed &= a01.m_vertices.GetCount() == 143845u;
        passed &= a01.m_triangles.GetCount() == 246803u;
        passed &= stadiumDecoration.m_vertices.GetCount() == 44182u;
        passed &= stadiumDecoration.m_triangles.GetCount() == 73051u;
        // CGameCtnBlock::GetMobilLoc at 0x0060ACB0 rotates around the full
        // ground/air block-info footprint. This coordinate fingerprint rejects
        // the former fixed-one-cell pivot and includes the map-selected
        // Square32 Stadium decoration collision solid.
        const uint64_t geometryHash = HashMeshVertices(a01);
        if (geometryHash != 0x7ED0BFA1FEABD5C3ull) {
            std::cerr << "A01 geometry fingerprint: 0x" << std::hex
                      << geometryHash << std::dec << '\n';
        }
        passed &= geometryHash == 0x7ED0BFA1FEABD5C3ull;
        const GmVec3 spawnRayPosition(171.199997f, 90.209999f, 688.0f);
        const GmVec3 spawnRayDirection(0.0f, -2.0f, 0.0f);
        hitT = 1.0f;
        passed &= a01.ClipSegment2(
            spawnRayPosition, spawnRayDirection, identity, hitT, hitNormal) != 0;
        passed &= Near(spawnRayPosition.y + spawnRayDirection.y * hitT,
                       90.0f, 1e-4f);
        passed &= Near(hitNormal.y, 1.0f, 1e-4f);
        hitT = 1.0f;
        material = 0xffff;
        passed &= a01.ClipSegment3(
            spawnRayPosition, spawnRayDirection, identity, hitT, material) != 0;
        passed &= material == 16;

        // A second load must reuse the fingerprinted cache and produce the
        // same mesh without invoking the extractor again.
        GmSurfMesh cachedA01;
        GmSurfMesh cachedDecoration;
        TrackMapLoadResult cachedResult;
        passed &= LoadTrackMapCollision(
            cachedA01, argv[1], options, &cachedResult,
            &cachedDecoration);
        passed &= cachedResult.cacheHit;
        passed &= cachedResult.collisionCachePath ==
            a01Result.collisionCachePath;
        passed &= cachedA01.m_vertices.GetCount() == a01.m_vertices.GetCount();
        passed &= cachedA01.m_triangles.GetCount() ==
            a01.m_triangles.GetCount();
        passed &= cachedDecoration.m_vertices.GetCount() ==
            stadiumDecoration.m_vertices.GetCount();

        StadiumVehicleAsset stadiumVehicle;
        StadiumVehicleLoadOptions vehicleOptions;
        vehicleOptions.packsDirectory = argv[2];
        vehicleOptions.extractorProject = argv[3];
        StadiumVehicleLoadResult vehicleResult;
        passed &= LoadStadiumVehicleAsset(
            stadiumVehicle, vehicleOptions, &vehicleResult);
        CPlugSolid* stadiumSolid = stadiumVehicle.CollisionSolid();
        passed &= stadiumSolid != nullptr && stadiumSolid->m_tree != nullptr;
        passed &= stadiumSolid != nullptr && stadiumSolid->m_tree != nullptr &&
            stadiumSolid->m_tree->GetChildCount() == 8u;
        passed &= stadiumVehicle.VisualMesh() != nullptr &&
            stadiumVehicle.VisualMesh()->m_vertices.GetCount() == 35199u &&
            stadiumVehicle.VisualMesh()->m_triangles.GetCount() == 69948u;
    }

    if (!passed) return 1;
    std::cout << "track collision loader/raycast regression passed\n";
    return 0;
}
