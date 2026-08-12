#include "VehicleAssetLoader.hpp"

#include "Gm/GmSurf.hpp"
#include "Plug/CPlugSolid.hpp"
#include "Plug/CPlugSurface.hpp"
#include "Plug/CPlugSurfaceGeom.hpp"
#include "Plug/CPlugTree.hpp"

#include <algorithm>
#include <cerrno>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <system_error>

#ifdef _WIN32
#include <process.h>
#else
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

namespace {

namespace fs = std::filesystem;

constexpr uint32_t kMaximumPrimitiveCount = 1024u;

template <typename T>
bool Read(std::ifstream& file, T& value) {
    file.read(reinterpret_cast<char*>(&value), sizeof(value));
    return static_cast<bool>(file);
}

bool IsFinite(const GmVec3& value) {
    return std::isfinite(value.x) && std::isfinite(value.y) &&
        std::isfinite(value.z);
}

bool IsFinite(const GmIso4& value) {
    const float* values = reinterpret_cast<const float*>(&value);
    for (std::size_t index = 0; index < 12u; ++index) {
        if (!std::isfinite(values[index])) return false;
    }
    return true;
}

std::string ExistingAbsolutePath(const fs::path& path) {
    std::error_code error;
    fs::path absolute = fs::absolute(path, error);
    if (error) return path.string();
    fs::path canonical = fs::weakly_canonical(absolute, error);
    return error ? absolute.lexically_normal().string() : canonical.string();
}

void HashBytes(uint64_t& hash, const void* bytes, std::size_t size) {
    const auto* data = static_cast<const unsigned char*>(bytes);
    for (std::size_t index = 0; index < size; ++index) {
        hash ^= data[index];
        hash *= 1099511628211ull;
    }
}

void HashString(uint64_t& hash, const std::string& value) {
    HashBytes(hash, value.data(), value.size());
    const unsigned char separator = 0xffu;
    HashBytes(hash, &separator, sizeof(separator));
}

bool HashFileIdentity(uint64_t& hash, const fs::path& path,
                      std::string& errorMessage) {
    std::error_code error;
    if (!fs::is_regular_file(path, error) || error) {
        errorMessage = "Required file does not exist: " + path.string();
        return false;
    }
    const uintmax_t size = fs::file_size(path, error);
    if (error) return false;
    const fs::file_time_type modified = fs::last_write_time(path, error);
    if (error) return false;
    HashString(hash, ExistingAbsolutePath(path));
    HashBytes(hash, &size, sizeof(size));
    const auto modifiedCount = modified.time_since_epoch().count();
    HashBytes(hash, &modifiedCount, sizeof(modifiedCount));
    return true;
}

bool EnsureDirectory(const fs::path& directory, std::string& errorMessage) {
    std::error_code error;
    if (fs::is_directory(directory, error) && !error) return true;
    error.clear();
    if (fs::create_directories(directory, error) ||
        (fs::is_directory(directory, error) && !error)) return true;
    errorMessage = "Could not create vehicle cache directory: " +
        directory.string();
    if (error) errorMessage += " (" + error.message() + ')';
    return false;
}

int RunProcess(const std::vector<std::string>& arguments) {
    if (arguments.empty()) return -1;
    std::vector<char*> argv;
    argv.reserve(arguments.size() + 1u);
    for (const std::string& argument : arguments)
        argv.push_back(const_cast<char*>(argument.c_str()));
    argv.push_back(nullptr);
#ifdef _WIN32
    return _spawnvp(_P_WAIT, argv[0], argv.data());
#else
    const pid_t child = fork();
    if (child < 0) return -1;
    if (child == 0) {
        execvp(argv[0], argv.data());
        std::fprintf(stderr, "Could not launch %s: %s\n", argv[0],
                     std::strerror(errno));
        _exit(127);
    }
    int status = 0;
    while (waitpid(child, &status, 0) < 0) {
        if (errno != EINTR) return -1;
    }
    return WIFEXITED(status) ? WEXITSTATUS(status) : -1;
#endif
}

bool BuildCachePaths(const StadiumVehicleLoadOptions& options,
                     fs::path& collisionPath, fs::path& visualPath,
                     std::string& errorMessage) {
    if (options.packsDirectory.empty() || options.extractorProject.empty()) {
        errorMessage = "Packs and TrackCollisionExtractor paths are required";
        return false;
    }
    const fs::path packs(options.packsDirectory);
    const fs::path project(options.extractorProject);
    uint64_t hash = 14695981039346656037ull;
    if (!HashFileIdentity(hash, packs / "packlist.dat", errorMessage) ||
        !HashFileIdentity(hash, packs / "Stadium.pak", errorMessage) ||
        !HashFileIdentity(hash, project, errorMessage) ||
        !HashFileIdentity(hash, project.parent_path() / "Program.cs",
                          errorMessage)) return false;

    fs::path cacheDirectory;
    if (!options.cacheDirectory.empty()) {
        cacheDirectory = options.cacheDirectory;
    } else {
        std::error_code error;
        cacheDirectory = fs::temp_directory_path(error);
        if (error) {
            errorMessage = "Could not determine the system temp directory";
            return false;
        }
        cacheDirectory /= "tmnf-physics-vehicle-cache";
    }
    if (!EnsureDirectory(cacheDirectory, errorMessage)) return false;
    std::ostringstream stem;
    stem << "StadiumCar-" << std::hex << std::setfill('0')
         << std::setw(16) << hash;
    collisionPath = cacheDirectory / (stem.str() + ".tmnfveh");
    visualPath = cacheDirectory / (stem.str() + ".obj");
    return true;
}

bool ExtractAssets(const StadiumVehicleLoadOptions& options,
                   const fs::path& collisionPath,
                   const fs::path& visualPath,
                   std::string& errorMessage) {
    const std::string suffix =
#ifdef _WIN32
        ".tmp." + std::to_string(_getpid());
#else
        ".tmp." + std::to_string(getpid());
#endif
    const fs::path temporaryCollision = collisionPath.string() + suffix;
    const fs::path temporaryVisual = visualPath.string() + suffix + ".obj";
    std::error_code ignored;
    fs::remove(temporaryCollision, ignored);
    fs::remove(temporaryVisual, ignored);
    const std::vector<std::string> arguments = {
        "dotnet", "run", "--no-restore", "--project",
        ExistingAbsolutePath(options.extractorProject), "--", "--vehicle",
        ExistingAbsolutePath(options.packsDirectory),
        temporaryCollision.string(), temporaryVisual.string(),
    };
    const int exitCode = RunProcess(arguments);
    if (exitCode != 0) {
        fs::remove(temporaryCollision, ignored);
        fs::remove(temporaryVisual, ignored);
        errorMessage = "Stadium vehicle extractor failed with exit code " +
            std::to_string(exitCode);
        return false;
    }

    StadiumVehicleAsset validation;
    if (!validation.LoadCollision(temporaryCollision.string(), &errorMessage)) {
        fs::remove(temporaryCollision, ignored);
        fs::remove(temporaryVisual, ignored);
        return false;
    }
    GmSurfMesh visualValidation;
    if (!visualValidation.LoadFromObj(temporaryVisual.string()) ||
        visualValidation.m_vertices.GetCount() == 0u ||
        visualValidation.m_triangles.GetCount() == 0u) {
        fs::remove(temporaryCollision, ignored);
        fs::remove(temporaryVisual, ignored);
        errorMessage = "Vehicle extractor produced an invalid visual OBJ";
        return false;
    }

    fs::remove(collisionPath, ignored);
    fs::remove(visualPath, ignored);
    ignored.clear();
    fs::rename(temporaryCollision, collisionPath, ignored);
    if (!ignored) fs::rename(temporaryVisual, visualPath, ignored);
    if (ignored) {
        fs::remove(temporaryCollision, ignored);
        fs::remove(temporaryVisual, ignored);
        errorMessage = "Could not publish Stadium vehicle cache";
        return false;
    }
    return true;
}

} // namespace

StadiumVehicleAsset::StadiumVehicleAsset()
    : m_visualMesh(std::make_unique<GmSurfMesh>()) {}

StadiumVehicleAsset::~StadiumVehicleAsset() = default;

bool StadiumVehicleAsset::LoadCollision(
    const std::string& path, std::string* outputError) {
    CPlugTree* wheelTrees[4] = {nullptr, nullptr, nullptr, nullptr};
    std::ifstream file(path, std::ios::binary);
    auto Fail = [&](const std::string& message) {
        if (outputError != nullptr) *outputError = message;
        return false;
    };
    if (!file.is_open()) return Fail("Could not open vehicle collision: " + path);
    char magic[8]{};
    uint32_t count = 0u;
    uint32_t reserved = 0u;
    file.read(magic, sizeof(magic));
    if (!Read(file, count) || !Read(file, reserved) ||
        std::memcmp(magic, "TMNFVEH1", sizeof(magic)) != 0 ||
        count == 0u || count > kMaximumPrimitiveCount) {
        return Fail("Invalid TMNFVEH1 header: " + path);
    }

    auto solid = std::make_unique<CPlugSolid>();
    auto root = std::make_unique<CPlugTree>();
    root->SetIsCollidable(true);
    std::vector<std::unique_ptr<CPlugTree>> trees;
    std::vector<std::unique_ptr<CPlugSurface>> surfaces;
    std::vector<std::unique_ptr<CPlugSurfaceGeom>> geometries;
    trees.reserve(count);
    surfaces.reserve(count);
    geometries.reserve(count);
    for (uint32_t index = 0u; index < count; ++index) {
        uint32_t type = 0u;
        uint16_t material = 0xffffu;
        uint16_t primitiveRole = 0u;
        GmVec3 radii;
        GmIso4 location;
        if (!Read(file, type) || !Read(file, material) ||
            !Read(file, primitiveRole) || !Read(file, radii) ||
            !Read(file, location) || type != 1u || !IsFinite(radii) ||
            radii.x <= 0.0f || radii.y <= 0.0f || radii.z <= 0.0f ||
            !IsFinite(location)) {
            return Fail("Invalid vehicle primitive " + std::to_string(index));
        }
        if (primitiveRole > 4u)
            return Fail("Invalid vehicle primitive role " +
                        std::to_string(primitiveRole));
        auto ellipsoid = new GmSurfEllipsoid();
        ellipsoid->m_radii = radii;
        auto geometry = std::make_unique<CPlugSurfaceGeom>();
        geometry->SetGmSurf(ellipsoid, true);
        auto surface = std::make_unique<CPlugSurface>();
        surface->m_geometry = geometry.get();
        surface->m_materialIds.Add(material);
        auto tree = std::make_unique<CPlugTree>();
        tree->SetSurface(surface.get());
        tree->SetLocation(location);
        tree->SetUseLocation(true);
        tree->SetIsCollidable(true);
        root->AddChild(tree.get());
        if (primitiveRole != 0u) {
            if (wheelTrees[primitiveRole - 1u] != nullptr)
                return Fail("Duplicate vehicle wheel collision role");
            wheelTrees[primitiveRole - 1u] = tree.get();
        }
        geometries.push_back(std::move(geometry));
        surfaces.push_back(std::move(surface));
        trees.push_back(std::move(tree));
    }
    char trailing = 0;
    if (file.read(&trailing, 1))
        return Fail("Unexpected trailing data in vehicle collision asset");
    solid->SetTree(root.get());
    m_solid = std::move(solid);
    m_root = std::move(root);
    m_trees = std::move(trees);
    m_surfaces = std::move(surfaces);
    m_geometries = std::move(geometries);
    std::copy(std::begin(wheelTrees), std::end(wheelTrees), m_wheelTrees);
    return true;
}

CPlugSolid* StadiumVehicleAsset::CollisionSolid() const {
    return m_solid.get();
}

CPlugTree* StadiumVehicleAsset::WheelCollisionTree(
    uint32_t wheelIndex) const {
    return wheelIndex < 4u ? m_wheelTrees[wheelIndex] : nullptr;
}

GmSurfMesh* StadiumVehicleAsset::VisualMesh() const {
    return m_visualMesh.get();
}

bool LoadStadiumVehicleAsset(
    StadiumVehicleAsset& asset,
    const StadiumVehicleLoadOptions& options,
    StadiumVehicleLoadResult* outputResult) {
    StadiumVehicleLoadResult localResult;
    StadiumVehicleLoadResult& result = outputResult != nullptr
        ? *outputResult : localResult;
    result = StadiumVehicleLoadResult{};
    fs::path collisionPath;
    fs::path visualPath;
    if (!BuildCachePaths(options, collisionPath, visualPath, result.error))
        return false;
    result.collisionCachePath = collisionPath.string();
    result.visualCachePath = visualPath.string();

    bool cacheValid = false;
    if (!options.forceCacheRebuild) {
        cacheValid = asset.LoadCollision(collisionPath.string(), nullptr) &&
            asset.m_visualMesh->LoadFromObj(visualPath.string()) &&
            asset.m_visualMesh->m_vertices.GetCount() != 0u &&
            asset.m_visualMesh->m_triangles.GetCount() != 0u;
    }
    if (cacheValid) {
        result.cacheHit = true;
        return true;
    }
    asset.m_visualMesh = std::make_unique<GmSurfMesh>();
    if (!ExtractAssets(options, collisionPath, visualPath, result.error))
        return false;
    if (!asset.LoadCollision(collisionPath.string(), &result.error) ||
        !asset.m_visualMesh->LoadFromObj(visualPath.string())) {
        result.error = "Could not load generated Stadium vehicle assets";
        return false;
    }
    result.cacheHit = false;
    return true;
}
