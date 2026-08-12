#include "GmSurf.hpp"
#include "GmFunc.hpp"
#include "TmForeverPhysicsConstants.hpp"
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <limits>
#include <memory>
#include <unordered_map>
#include <vector>

namespace {

struct GmSurfMeshSpatialIndex {
    static constexpr float kCellSize = 32.0f;
    float minX = 0.0f;
    float minZ = 0.0f;
    uint32_t sizeX = 0;
    uint32_t sizeZ = 0;
    std::vector<std::vector<uint32_t>> cells;

    const std::vector<uint32_t>* GetCell(float x, float z) const {
        if (sizeX == 0 || sizeZ == 0) return nullptr;
        const int cellX = static_cast<int>(std::floor((x - minX) / kCellSize));
        const int cellZ = static_cast<int>(std::floor((z - minZ) / kCellSize));
        if (cellX < 0 || cellZ < 0 || cellX >= static_cast<int>(sizeX) ||
            cellZ >= static_cast<int>(sizeZ)) {
            return nullptr;
        }
        return &cells[static_cast<uint32_t>(cellZ) * sizeX +
                      static_cast<uint32_t>(cellX)];
    }
};

std::unordered_map<const GmSurfMesh*, std::unique_ptr<GmSurfMeshSpatialIndex>>
    g_gmSurfMeshSpatialIndices;

const std::vector<uint32_t>* GmSurfMesh_GetVerticalRayCandidates(
    const GmSurfMesh* mesh, const GmVec3& localPos, const GmVec3& localDir) {
    if (std::abs(localDir.x) > 1e-6f || std::abs(localDir.z) > 1e-6f)
        return nullptr;
    const auto found = g_gmSurfMeshSpatialIndices.find(mesh);
    if (found == g_gmSurfMeshSpatialIndices.end()) return nullptr;
    return found->second->GetCell(localPos.x, localPos.z);
}

} // namespace

GmSurfMesh::GmSurfMesh() {
    m_type = 7;
}

GmSurfMesh::~GmSurfMesh() {
    g_gmSurfMeshSpatialIndices.erase(this);
}

int GmSurfMesh::TriangleClipSegmentNearerThanT(const GmVec3& rayPos, const GmVec3& rayDir, const GmVec3& triNormal, float& outT, SPointInTri& outPoint) {
    // 1. Plane Intersection
    // triNormal is normalized. planeDist is -Dot(triNormal, v0)
    // We need the triangle to have the plane equation stored or passed.
    // In our manual GmSurfTriangle, we have planeNormal and planeDist.
    
    float distOrigin = GmVec3::Dot(triNormal, rayPos);
    float dotDir = GmVec3::Dot(triNormal, rayDir);
    
    if (std::abs(dotDir) < 1e-6f) return 0; // Parallel
    
    // We assume the triangle is in the mesh local space.
    // In our simplified test, we'll find the planeDist here if not set.
    // For now, assume tri.planeDist is correct.
    
    // Find t where (rayPos + t*rayDir) is on plane
    // dot(triNormal, rayPos + t*rayDir) + planeDist = 0
    // t = -(dot(triNormal, rayPos) + planeDist) / dot(triNormal, rayDir)
    
    return 0; // The actual unrolled math from dump is below
}

// Re-translating the exact unrolled math for TriangleClipSegmentNearerThanT
// from tmnf_dump/src/GmSurfMesh.cpp:627
int GmSurfMesh_TriangleClipSegmentNearerThanT_Real(
    const GmVec3& normal, float planeDist, 
    const GmVec3& v0, const GmVec3& v1, const GmVec3& v2,
    const GmVec3& rayPos, const GmVec3& rayDir, float& outT) 
{
    float fVar2 = normal.z * rayPos.z + normal.x * rayPos.x + normal.y * rayPos.y + planeDist;
    if (fVar2 < 0.0f) return 0; // Ray origin is behind plane

    float fVar3 = -(normal.z * (rayPos.z + rayDir.z) + normal.x * (rayPos.x + rayDir.x) + normal.y * (rayPos.y + rayDir.y) + planeDist);
    
    float hitT;
    // GmFunc::Div equivalent
    if (std::abs(fVar2) * 1e-9f < std::abs(fVar3 + fVar2)) {
        hitT = fVar2 / (fVar2 + fVar3);
        if (hitT >= 0.0f && hitT <= outT) {
            // Barycentric check (inside triangle)
            GmVec3 hitPoint = rayPos + rayDir * hitT;
            
            // Project to 2D by dropping most significant axis of normal
            int axis = 0;
            float nx = std::abs(normal.x);
            float ny = std::abs(normal.y);
            float nz = std::abs(normal.z);
            if (ny > nx) { nx = ny; axis = 1; }
            if (nz > nx) axis = 2;
            
            int u = (axis + 1) % 3;
            int v = (axis + 2) % 3;
            
            float hitU = (&hitPoint.x)[u], hitV = (&hitPoint.x)[v];
            float aU = (&v0.x)[u], aV = (&v0.x)[v];
            float bU = (&v1.x)[u], bV = (&v1.x)[v];
            float cU = (&v2.x)[u], cV = (&v2.x)[v];
            
            // Area-based barycentric coords
            float det = (bV - cV)*(aU - cU) + (cU - bU)*(aV - cV);
            if (std::abs(det) < 1e-9f) return 0;
            
            float alpha = ((bV - cV)*(hitU - cU) + (cU - bU)*(hitV - cV)) / det;
            float beta = ((cV - aV)*(hitU - cU) + (aU - cU)*(hitV - cV)) / det;
            float gamma = 1.0f - alpha - beta;
            
            if (alpha >= 0.0f && beta >= 0.0f && gamma >= 0.0f) {
                outT = hitT;
                return 1;
            }
        }
    }
    return 0;
}

int GmSurfMesh::ClipSegment(const GmVec3& rayPos, const GmVec3& rayDir, const GmIso4& transform, float& outT) {
    GmVec3 localPos = transform.UnTransform(rayPos);
    GmVec3 localDir = transform.UnTransformVector(rayDir);
    
    bool hit = false;
    float currentT = outT;
    
    const std::vector<uint32_t>* candidates =
        GmSurfMesh_GetVerticalRayCandidates(this, localPos, localDir);
    const uint32_t candidateCount = candidates == nullptr
        ? m_triangles.m_count
        : static_cast<uint32_t>(candidates->size());
    for (uint32_t candidate = 0; candidate < candidateCount; ++candidate) {
        const uint32_t i = candidates == nullptr ? candidate : (*candidates)[candidate];
        GmSurfTriangle& tri = m_triangles[i];
        if (GmSurfMesh_TriangleClipSegmentNearerThanT_Real(
            tri.planeNormal, tri.planeDist,
            m_vertices[tri.indices[0]], m_vertices[tri.indices[1]], m_vertices[tri.indices[2]],
            localPos, localDir, currentT)) 
        {
            hit = true;
        }
    }
    
    if (hit) outT = currentT;
    return hit;
}

int GmSurfMesh::ClipSegment2(
    const GmVec3& rayPos,
    const GmVec3& rayDir,
    const GmIso4& transform,
    float& outT,
    GmVec3& outNormal) {
    GmVec3 localPos = transform.UnTransform(rayPos);
    GmVec3 localDir = transform.UnTransformVector(rayDir);

    bool hit = false;
    float currentT = outT;
    GmVec3 localNormal(0.0f, 0.0f, 0.0f);
    const std::vector<uint32_t>* candidates =
        GmSurfMesh_GetVerticalRayCandidates(this, localPos, localDir);
    const uint32_t candidateCount = candidates == nullptr
        ? m_triangles.m_count
        : static_cast<uint32_t>(candidates->size());
    for (uint32_t candidate = 0; candidate < candidateCount; ++candidate) {
        const uint32_t i = candidates == nullptr ? candidate : (*candidates)[candidate];
        GmSurfTriangle& triangle = m_triangles[i];
        if (triangle.indices[0] >= m_vertices.m_count ||
            triangle.indices[1] >= m_vertices.m_count ||
            triangle.indices[2] >= m_vertices.m_count) {
            continue;
        }
        if (GmSurfMesh_TriangleClipSegmentNearerThanT_Real(
                triangle.planeNormal,
                triangle.planeDist,
                m_vertices[triangle.indices[0]],
                m_vertices[triangle.indices[1]],
                m_vertices[triangle.indices[2]],
                localPos,
                localDir,
                currentT)) {
            hit = true;
            localNormal = triangle.planeNormal;
        }
    }

    if (!hit) return 0;
    outT = currentT;
    outNormal = GmVec3(
        transform.m00 * localNormal.x + transform.m01 * localNormal.y +
            transform.m02 * localNormal.z,
        transform.m10 * localNormal.x + transform.m11 * localNormal.y +
            transform.m12 * localNormal.z,
        transform.m20 * localNormal.x + transform.m21 * localNormal.y +
            transform.m22 * localNormal.z);
    outNormal.Normalize();
    return 1;
}

int GmSurfMesh::ClipSegment3(
    const GmVec3& rayPos,
    const GmVec3& rayDir,
    const GmIso4& transform,
    float& outT,
    uint16_t& outId) {
    GmVec3 localPos = transform.UnTransform(rayPos);
    GmVec3 localDir = transform.UnTransformVector(rayDir);

    bool hit = false;
    float currentT = outT;
    uint16_t currentId = 0xffff;
    const std::vector<uint32_t>* candidates =
        GmSurfMesh_GetVerticalRayCandidates(this, localPos, localDir);
    const uint32_t candidateCount = candidates == nullptr
        ? m_triangles.m_count
        : static_cast<uint32_t>(candidates->size());
    for (uint32_t candidate = 0; candidate < candidateCount; ++candidate) {
        const uint32_t i = candidates == nullptr ? candidate : (*candidates)[candidate];
        GmSurfTriangle& triangle = m_triangles[i];
        if (triangle.indices[0] >= m_vertices.m_count ||
            triangle.indices[1] >= m_vertices.m_count ||
            triangle.indices[2] >= m_vertices.m_count) {
            continue;
        }
        if (GmSurfMesh_TriangleClipSegmentNearerThanT_Real(
                triangle.planeNormal,
                triangle.planeDist,
                m_vertices[triangle.indices[0]],
                m_vertices[triangle.indices[1]],
                m_vertices[triangle.indices[2]],
                localPos,
                localDir,
                currentT)) {
            hit = true;
            currentId = triangle.materialId;
        }
    }

    if (!hit) return 0;
    outT = currentT;
    outId = currentId;
    return 1;
}

void GmSurfMesh::GetMeshBoundingBox(GmBoxAligned& outBox) const {
    outBox.InitEmpty();
    // Native 0x008f02d0 returns the root octree bounds when triangles exist,
    // and an empty box otherwise. The standalone broadphase is a side table,
    // so reconstruct the same root geometry from referenced face vertices.
    if (m_triangles.m_count == 0u) return;
    for (uint32_t triangleIndex = 0;
         triangleIndex < m_triangles.m_count;
         ++triangleIndex) {
        const GmSurfTriangle& triangle = m_triangles[triangleIndex];
        for (uint32_t corner = 0; corner < 3u; ++corner) {
            if (triangle.indices[corner] < m_vertices.m_count) {
                outBox.Union(m_vertices[triangle.indices[corner]]);
            }
        }
    }
}

void GmSurfMesh::BuildOctree() {
    g_gmSurfMeshSpatialIndices.erase(this);
    if (m_vertices.m_count == 0 || m_triangles.m_count == 0) return;

    float minX = std::numeric_limits<float>::infinity();
    float minZ = std::numeric_limits<float>::infinity();
    float maxX = -std::numeric_limits<float>::infinity();
    float maxZ = -std::numeric_limits<float>::infinity();
    for (uint32_t i = 0; i < m_vertices.m_count; ++i) {
        minX = std::min(minX, m_vertices[i].x);
        minZ = std::min(minZ, m_vertices[i].z);
        maxX = std::max(maxX, m_vertices[i].x);
        maxZ = std::max(maxZ, m_vertices[i].z);
    }

    auto index = std::make_unique<GmSurfMeshSpatialIndex>();
    index->minX = std::floor(minX / GmSurfMeshSpatialIndex::kCellSize) *
                  GmSurfMeshSpatialIndex::kCellSize;
    index->minZ = std::floor(minZ / GmSurfMeshSpatialIndex::kCellSize) *
                  GmSurfMeshSpatialIndex::kCellSize;
    index->sizeX = static_cast<uint32_t>(
        std::floor((maxX - index->minX) / GmSurfMeshSpatialIndex::kCellSize)) + 1u;
    index->sizeZ = static_cast<uint32_t>(
        std::floor((maxZ - index->minZ) / GmSurfMeshSpatialIndex::kCellSize)) + 1u;
    if (index->sizeX > 4096u || index->sizeZ > 4096u ||
        static_cast<uint64_t>(index->sizeX) * index->sizeZ > 1000000u) {
        return;
    }
    index->cells.resize(static_cast<size_t>(index->sizeX) * index->sizeZ);

    for (uint32_t triangleIndex = 0; triangleIndex < m_triangles.m_count;
         ++triangleIndex) {
        const GmSurfTriangle& triangle = m_triangles[triangleIndex];
        if (triangle.indices[0] >= m_vertices.m_count ||
            triangle.indices[1] >= m_vertices.m_count ||
            triangle.indices[2] >= m_vertices.m_count) {
            continue;
        }
        const GmVec3& a = m_vertices[triangle.indices[0]];
        const GmVec3& b = m_vertices[triangle.indices[1]];
        const GmVec3& c = m_vertices[triangle.indices[2]];
        const float triangleMinX = std::min(a.x, std::min(b.x, c.x));
        const float triangleMaxX = std::max(a.x, std::max(b.x, c.x));
        const float triangleMinZ = std::min(a.z, std::min(b.z, c.z));
        const float triangleMaxZ = std::max(a.z, std::max(b.z, c.z));
        const int firstX = std::max(0, static_cast<int>(std::floor(
            (triangleMinX - index->minX) / GmSurfMeshSpatialIndex::kCellSize)));
        const int lastX = std::min(static_cast<int>(index->sizeX) - 1,
            static_cast<int>(std::floor(
                (triangleMaxX - index->minX) / GmSurfMeshSpatialIndex::kCellSize)));
        const int firstZ = std::max(0, static_cast<int>(std::floor(
            (triangleMinZ - index->minZ) / GmSurfMeshSpatialIndex::kCellSize)));
        const int lastZ = std::min(static_cast<int>(index->sizeZ) - 1,
            static_cast<int>(std::floor(
                (triangleMaxZ - index->minZ) / GmSurfMeshSpatialIndex::kCellSize)));
        for (int z = firstZ; z <= lastZ; ++z) {
            for (int x = firstX; x <= lastX; ++x) {
                index->cells[static_cast<uint32_t>(z) * index->sizeX +
                             static_cast<uint32_t>(x)].push_back(triangleIndex);
            }
        }
    }

    g_gmSurfMeshSpatialIndices.emplace(this, std::move(index));
}

bool GmSurfMesh::GetAabbCandidates(
    float minX, float minZ, float maxX, float maxZ,
    std::vector<uint32_t>& outCandidates) const {
    outCandidates.clear();
    const auto found = g_gmSurfMeshSpatialIndices.find(this);
    if (found == g_gmSurfMeshSpatialIndices.end()) return false;
    const GmSurfMeshSpatialIndex& index = *found->second;
    if (index.sizeX == 0u || index.sizeZ == 0u) return true;
    if (minX > maxX) std::swap(minX, maxX);
    if (minZ > maxZ) std::swap(minZ, maxZ);
    int firstX = static_cast<int>(std::floor(
        (minX - index.minX) / GmSurfMeshSpatialIndex::kCellSize));
    int lastX = static_cast<int>(std::floor(
        (maxX - index.minX) / GmSurfMeshSpatialIndex::kCellSize));
    int firstZ = static_cast<int>(std::floor(
        (minZ - index.minZ) / GmSurfMeshSpatialIndex::kCellSize));
    int lastZ = static_cast<int>(std::floor(
        (maxZ - index.minZ) / GmSurfMeshSpatialIndex::kCellSize));
    if (lastX < 0 || lastZ < 0 || firstX >= static_cast<int>(index.sizeX) ||
        firstZ >= static_cast<int>(index.sizeZ)) {
        return true;
    }
    firstX = std::max(firstX, 0);
    firstZ = std::max(firstZ, 0);
    lastX = std::min(lastX, static_cast<int>(index.sizeX) - 1);
    lastZ = std::min(lastZ, static_cast<int>(index.sizeZ) - 1);
    for (int z = firstZ; z <= lastZ; ++z) {
        for (int x = firstX; x <= lastX; ++x) {
            const std::vector<uint32_t>& cell = index.cells[
                static_cast<uint32_t>(z) * index.sizeX +
                static_cast<uint32_t>(x)];
            outCandidates.insert(
                outCandidates.end(), cell.begin(), cell.end());
        }
    }
    std::sort(outCandidates.begin(), outCandidates.end());
    outCandidates.erase(
        std::unique(outCandidates.begin(), outCandidates.end()),
        outCandidates.end());
    return true;
}
void GmSurfMesh::TransformByNOMat(const GmIso4& transform) {
    // Native 0x008f3ea0 first bakes the affine transform into every vertex.
    // It only rebuilds triangle planes when the transform changes handedness;
    // direct transforms deliberately leave the stored planes untouched.
    const bool hadSpatialIndex =
        g_gmSurfMeshSpatialIndices.find(this) !=
        g_gmSurfMeshSpatialIndices.end();
    for (uint32_t vertexIndex = 0;
         vertexIndex < m_vertices.m_count;
         ++vertexIndex) {
        m_vertices[vertexIndex].Mult(transform);
    }

    if (transform.rot.IsIndirect()) {
        for (uint32_t triangleIndex = 0;
             triangleIndex < m_triangles.m_count;
             ++triangleIndex) {
            GmSurfTriangle& triangle = m_triangles[triangleIndex];
            std::swap(triangle.indices[1], triangle.indices[2]);
            if (triangle.indices[0] >= m_vertices.m_count ||
                triangle.indices[1] >= m_vertices.m_count ||
                triangle.indices[2] >= m_vertices.m_count) {
                continue;
            }

            const GmVec3& first = m_vertices[triangle.indices[0]];
            const GmVec3 edgeA =
                m_vertices[triangle.indices[1]] - first;
            const GmVec3 edgeB =
                m_vertices[triangle.indices[2]] - first;
            GmVec3 normal = GmVec3::Cross(edgeA, edgeB);
            const float normalLengthSquared = GmVec3::Dot(normal, normal);
            if (normalLengthSquared >
                TmForeverPhysicsConstants::
                    kMeshTransformNormalSquaredEpsilon) {
                normal *= 1.0f / std::sqrt(normalLengthSquared);
            }
            triangle.planeNormal = normal;
            triangle.planeDist = -GmVec3::Dot(normal, first);
        }
    }

    // The executable rebuilds its octree only when one was already present.
    // The standalone vertical-ray side table is the corresponding broadphase
    // cache and must follow the same invalidation rule.
    if (m_octree.GetCount() != 0u || hadSpatialIndex) BuildOctree();
}

#include <sstream>

bool GmSurfMesh::LoadFromObj(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;
    
    // CFastArray::Add reallocates and copies the entire array for every single
    // element, so appending a few hundred thousand vertices one at a time is
    // quadratic. Accumulate locally and commit once at the end. Seeded from the
    // current contents so repeated loads still append, as they did before.
    std::vector<GmVec3> vertices(
        m_vertices.m_data, m_vertices.m_data + m_vertices.m_count);
    std::vector<GmSurfTriangle> triangles(
        m_triangles.m_data, m_triangles.m_data + m_triangles.m_count);

    std::string line;
    while (std::getline(file, line)) {
        const char* cursor = line.c_str();
        while (*cursor == ' ' || *cursor == '\t') ++cursor;
        const bool isValue = cursor[0] != '\0' &&
            (cursor[1] == ' ' || cursor[1] == '\t');
        if (!isValue) continue;

        if (cursor[0] == 'v') {
            char* end = nullptr;
            const float x = std::strtof(cursor + 1, &end);
            const float y = std::strtof(end, &end);
            const float z = std::strtof(end, &end);
            vertices.push_back(GmVec3(x, y, z));
        } else if (cursor[0] == 'f' && !vertices.empty()) {
            GmSurfTriangle tri{};
            const char* scan = cursor + 1;
            bool complete = true;
            for (int i = 0; i < 3; ++i) {
                while (*scan == ' ' || *scan == '\t') ++scan;
                char* end = nullptr;
                const long parsed = std::strtol(scan, &end, 10);
                if (end == scan) {
                    complete = false;
                    break;
                }
                // Skip any texture/normal components of "v/vt/vn".
                scan = end;
                while (*scan != '\0' && *scan != ' ' && *scan != '\t') ++scan;
                uint32_t index = static_cast<uint32_t>(parsed - 1);
                if (index >= vertices.size()) {
                    index = static_cast<uint32_t>(vertices.size() - 1);
                }
                tri.indices[i] = index;
            }
            if (!complete) continue;

            // Compute plane normal
            const GmVec3& v0 = vertices[tri.indices[0]];
            const GmVec3& v1 = vertices[tri.indices[1]];
            const GmVec3& v2 = vertices[tri.indices[2]];

            GmVec3 edge1 = v1 - v0;
            GmVec3 edge2 = v2 - v0;
            tri.planeNormal = GmVec3::Cross(edge1, edge2);
            tri.planeNormal.Normalize();
            tri.planeDist = -GmVec3::Dot(tri.planeNormal, v0);

            triangles.push_back(tri);
        }
    }

    m_vertices.SetCount(static_cast<uint32_t>(vertices.size()));
    std::copy(vertices.begin(), vertices.end(), m_vertices.m_data);
    m_triangles.SetCount(static_cast<uint32_t>(triangles.size()));
    std::copy(triangles.begin(), triangles.end(), m_triangles.m_data);

    BuildOctree();
    return true;
}

bool GmSurfMesh::LoadFromTmnfCollision(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) return false;

    char magic[8];
    uint32_t vertexCount = 0;
    uint32_t triangleCount = 0;
    uint32_t blockCount = 0;
    uint32_t reserved = 0;
    file.read(magic, sizeof(magic));
    file.read(reinterpret_cast<char*>(&vertexCount), sizeof(vertexCount));
    file.read(reinterpret_cast<char*>(&triangleCount), sizeof(triangleCount));
    file.read(reinterpret_cast<char*>(&blockCount), sizeof(blockCount));
    file.read(reinterpret_cast<char*>(&reserved), sizeof(reserved));
    (void)blockCount;
    (void)reserved;
    if (!file || std::memcmp(magic, "TMNFCOL1", sizeof(magic)) != 0 ||
        vertexCount > 100000000u || triangleCount > 100000000u) {
        return false;
    }

    std::vector<GmVec3> vertices(vertexCount);
    std::vector<GmSurfTriangle> triangles(triangleCount);
    for (uint32_t i = 0; i < vertexCount; ++i) {
        file.read(reinterpret_cast<char*>(&vertices[i].x), sizeof(float));
        file.read(reinterpret_cast<char*>(&vertices[i].y), sizeof(float));
        file.read(reinterpret_cast<char*>(&vertices[i].z), sizeof(float));
        if (!file || !std::isfinite(vertices[i].x) ||
            !std::isfinite(vertices[i].y) || !std::isfinite(vertices[i].z)) {
            return false;
        }
    }

    for (uint32_t i = 0; i < triangleCount; ++i) {
        GmSurfTriangle& triangle = triangles[i];
        uint16_t padding = 0;
        file.read(reinterpret_cast<char*>(&triangle.indices[0]), sizeof(uint32_t));
        file.read(reinterpret_cast<char*>(&triangle.indices[1]), sizeof(uint32_t));
        file.read(reinterpret_cast<char*>(&triangle.indices[2]), sizeof(uint32_t));
        file.read(reinterpret_cast<char*>(&triangle.planeNormal.x), sizeof(float));
        file.read(reinterpret_cast<char*>(&triangle.planeNormal.y), sizeof(float));
        file.read(reinterpret_cast<char*>(&triangle.planeNormal.z), sizeof(float));
        file.read(reinterpret_cast<char*>(&triangle.planeDist), sizeof(float));
        file.read(reinterpret_cast<char*>(&triangle.materialId), sizeof(uint16_t));
        file.read(reinterpret_cast<char*>(&padding), sizeof(uint16_t));
        if (!file || triangle.indices[0] >= vertexCount ||
            triangle.indices[1] >= vertexCount || triangle.indices[2] >= vertexCount ||
            !std::isfinite(triangle.planeNormal.x) ||
            !std::isfinite(triangle.planeNormal.y) ||
            !std::isfinite(triangle.planeNormal.z) ||
            !std::isfinite(triangle.planeDist)) {
            return false;
        }
    }

    // Reject appended/truncated variants of the format.  A valid file ends at
    // the last triangle record.
    if (file.peek() != std::ifstream::traits_type::eof()) return false;

    m_vertices.SetCount(vertexCount);
    m_triangles.SetCount(triangleCount);
    for (uint32_t i = 0; i < vertexCount; ++i) m_vertices[i] = vertices[i];
    for (uint32_t i = 0; i < triangleCount; ++i) m_triangles[i] = triangles[i];
    BuildOctree();
    return true;
}
