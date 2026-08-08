#ifndef TRACKMAPLOADER_HPP
#define TRACKMAPLOADER_HPP

#include <cstddef>
#include <string>

class GmSurfMesh;

struct TrackMapLoadOptions {
    // Required for Challenge.Gbx inputs. The extractor reads packlist.dat and
    // Stadium.pak from this directory.
    std::string packsDirectory;

    // Path to TrackCollisionExtractor.csproj. This is the current bridge for
    // decoding the encrypted PAK and its CPlugSolid collision nodes.
    std::string extractorProject;

    // Empty selects a tmnf-physics-map-cache directory under the system temp
    // directory. The cache name includes source/PAK/extractor fingerprints.
    std::string cacheDirectory;
    bool forceCacheRebuild = false;
};

struct TrackMapLoadResult {
    std::string mapName;
    std::string mapUid;
    std::string mapAuthor;
    std::string environment;
    std::string collisionCachePath;
    std::string error;
    std::size_t blockCount = 0;
    bool sourceWasChallengeGbx = false;
    bool cacheHit = false;
};

// Loads either an existing TMNFCOL1 file or a TMNF Challenge.Gbx. Challenge
// files are parsed natively for map data, then their block solids are resolved
// from Stadium.pak by TrackCollisionExtractor and cached before being loaded
// into GmSurfMesh.
bool LoadTrackMapCollision(
    GmSurfMesh& mesh,
    const std::string& mapOrCollisionPath,
    const TrackMapLoadOptions& options,
    TrackMapLoadResult* result = nullptr);

#endif // TRACKMAPLOADER_HPP
