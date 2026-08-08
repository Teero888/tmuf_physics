#include "Gm/GmSurf.hpp"
#include "Track/TrackMapLoader.hpp"

#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

class CSceneVehicleCarTuning;
CSceneVehicleCarTuning* g_tuning = nullptr;

namespace {

bool Near(float actual, float expected, float tolerance = 1e-6f) {
    if (std::abs(actual - expected) <= tolerance) return true;
    std::cerr << "expected " << expected << ", got " << actual << '\n';
    return false;
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

    if (argc != 1 && argc != 4) {
        std::cerr << "Usage: " << argv[0]
                  << " [A01-Race.Challenge.Gbx PacksDirectory "
                     "TrackCollisionExtractor.csproj]\n";
        return 2;
    }

    if (argc == 4) {
        GmSurfMesh a01;
        TrackMapLoadOptions options;
        options.packsDirectory = argv[2];
        options.extractorProject = argv[3];
        TrackMapLoadResult a01Result;
        passed &= LoadTrackMapCollision(a01, argv[1], options, &a01Result);
        passed &= a01Result.sourceWasChallengeGbx;
        passed &= a01Result.mapName == "A01-Race";
        passed &= a01Result.mapAuthor == "Nadeo";
        passed &= a01Result.environment == "Stadium";
        passed &= a01Result.blockCount == 397;
        passed &= a01.m_vertices.GetCount() == 98089;
        passed &= a01.m_triangles.GetCount() == 176184;
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
        TrackMapLoadResult cachedResult;
        passed &= LoadTrackMapCollision(
            cachedA01, argv[1], options, &cachedResult);
        passed &= cachedResult.cacheHit;
        passed &= cachedResult.collisionCachePath ==
            a01Result.collisionCachePath;
        passed &= cachedA01.m_vertices.GetCount() == a01.m_vertices.GetCount();
        passed &= cachedA01.m_triangles.GetCount() ==
            a01.m_triangles.GetCount();
    }

    if (!passed) return 1;
    std::cout << "track collision loader/raycast regression passed\n";
    return 0;
}
