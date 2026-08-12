#ifndef VEHICLEASSETLOADER_HPP
#define VEHICLEASSETLOADER_HPP

#include <memory>
#include <cstdint>
#include <string>
#include <vector>

class CPlugSolid;
class CPlugSurface;
class CPlugSurfaceGeom;
class CPlugTree;
class GmSurfMesh;

struct StadiumVehicleLoadOptions {
    std::string packsDirectory;
    std::string extractorProject;
    std::string cacheDirectory;
    bool forceCacheRebuild = false;
};

struct StadiumVehicleLoadResult {
    std::string collisionCachePath;
    std::string visualCachePath;
    std::string error;
    bool cacheHit = false;
};

// Owns the native StadiumCar CPlugSolid collision hierarchy decoded from the
// installation. TMNF uses eight located GmSurfEllipsoid primitives rather
// than a rectangular chassis proxy.
class StadiumVehicleAsset {
public:
    StadiumVehicleAsset();
    ~StadiumVehicleAsset();

    StadiumVehicleAsset(const StadiumVehicleAsset&) = delete;
    StadiumVehicleAsset& operator=(const StadiumVehicleAsset&) = delete;

    bool LoadCollision(const std::string& path, std::string* error = nullptr);
    CPlugSolid* CollisionSolid() const;
    CPlugTree* WheelCollisionTree(uint32_t wheelIndex) const;
    GmSurfMesh* VisualMesh() const;

private:
    std::unique_ptr<CPlugSolid> m_solid;
    std::unique_ptr<CPlugTree> m_root;
    std::vector<std::unique_ptr<CPlugTree>> m_trees;
    std::vector<std::unique_ptr<CPlugSurface>> m_surfaces;
    std::vector<std::unique_ptr<CPlugSurfaceGeom>> m_geometries;
    std::unique_ptr<GmSurfMesh> m_visualMesh;
    CPlugTree* m_wheelTrees[4]{};

    friend bool LoadStadiumVehicleAsset(
        StadiumVehicleAsset& asset,
        const StadiumVehicleLoadOptions& options,
        StadiumVehicleLoadResult* result);
};

bool LoadStadiumVehicleAsset(
    StadiumVehicleAsset& asset,
    const StadiumVehicleLoadOptions& options,
    StadiumVehicleLoadResult* result = nullptr);

#endif
