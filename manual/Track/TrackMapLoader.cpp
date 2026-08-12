#include "TrackMapLoader.hpp"

#include "Gm/GmSurf.hpp"

extern "C" {
#include "gbx_map/gbx_map.h"
}

#include <algorithm>
#include <cerrno>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include <system_error>
#include <vector>

#ifdef _WIN32
#include <process.h>
#else
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

namespace {

namespace fs = std::filesystem;

struct ChallengeDeleter {
    void operator()(gbx_map_challenge_t* challenge) const {
        gbx_map_challenge_free(challenge);
    }
};

using ChallengePtr = std::unique_ptr<gbx_map_challenge_t, ChallengeDeleter>;

void SetError(TrackMapLoadResult& result, const std::string& error) {
    result.error = error;
}

std::string Lowercase(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(),
        [](unsigned char character) {
            return static_cast<char>(std::tolower(character));
        });
    return value;
}

bool IsCollisionCachePath(const fs::path& path) {
    return Lowercase(path.extension().string()) == ".tmnfcol";
}

bool IsChallengeGbxPath(const fs::path& path) {
    const std::string lower = Lowercase(path.filename().string());
    const std::string suffix = ".challenge.gbx";
    return lower.size() >= suffix.size() &&
        lower.compare(lower.size() - suffix.size(), suffix.size(), suffix) == 0;
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
    for (std::size_t i = 0; i < size; ++i) {
        hash ^= data[i];
        hash *= 1099511628211ull;
    }
}

void HashString(uint64_t& hash, const std::string& value) {
    HashBytes(hash, value.data(), value.size());
    const unsigned char separator = 0xff;
    HashBytes(hash, &separator, sizeof(separator));
}

bool HashFileIdentity(
    uint64_t& hash,
    const fs::path& path,
    std::string& errorMessage) {
    std::error_code error;
    if (!fs::is_regular_file(path, error) || error) {
        errorMessage = "Required file does not exist: " + path.string();
        return false;
    }
    const uintmax_t size = fs::file_size(path, error);
    if (error) {
        errorMessage = "Could not read file size: " + path.string();
        return false;
    }
    const fs::file_time_type modified = fs::last_write_time(path, error);
    if (error) {
        errorMessage = "Could not read file timestamp: " + path.string();
        return false;
    }

    HashString(hash, ExistingAbsolutePath(path));
    HashBytes(hash, &size, sizeof(size));
    const auto modifiedCount = modified.time_since_epoch().count();
    HashBytes(hash, &modifiedCount, sizeof(modifiedCount));
    return true;
}

std::string SafeStem(const fs::path& path) {
    std::string stem = path.stem().string();
    // Strip the second extension in *.Challenge.Gbx.
    if (Lowercase(fs::path(stem).extension().string()) == ".challenge")
        stem = fs::path(stem).stem().string();
    for (char& character : stem) {
        const unsigned char value = static_cast<unsigned char>(character);
        if (!std::isalnum(value) && character != '-' && character != '_')
            character = '_';
    }
    return stem.empty() ? "track" : stem;
}

bool EnsureDirectory(const fs::path& directory, std::string& errorMessage) {
    std::error_code error;
    if (fs::is_directory(directory, error) && !error) return true;
    error.clear();
    if (fs::create_directories(directory, error) ||
        (fs::is_directory(directory, error) && !error)) {
        return true;
    }
    errorMessage = "Could not create map cache directory: " +
        directory.string();
    if (error) errorMessage += " (" + error.message() + ")";
    return false;
}

int RunProcess(const std::vector<std::string>& arguments) {
    if (arguments.empty()) return -1;
    std::vector<char*> argv;
    argv.reserve(arguments.size() + 1);
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
    if (WIFEXITED(status)) return WEXITSTATUS(status);
    return -1;
#endif
}

bool ParseChallenge(
    const std::string& challengePath,
    TrackMapLoadResult& result) {
    gbx_map_challenge_t* rawChallenge = nullptr;
    const int parseResult =
        gbx_map_parse_challenge(challengePath.c_str(), &rawChallenge);
    ChallengePtr challenge(rawChallenge);
    if (parseResult != 0 || challenge == nullptr) {
        SetError(result, "Could not parse Challenge.Gbx (gbx_map error " +
            std::to_string(parseResult) + "): " + challengePath);
        return false;
    }

    if (challenge->map_name != nullptr) result.mapName = challenge->map_name;
    if (challenge->map_uid != nullptr) result.mapUid = challenge->map_uid;
    if (challenge->map_author != nullptr)
        result.mapAuthor = challenge->map_author;
    if (challenge->environment != nullptr)
        result.environment = challenge->environment;
    result.blockCount = challenge->num_blocks;

    if (Lowercase(result.environment) != "stadium") {
        SetError(result, "Only TMNF Stadium maps are currently supported; map "
            "environment is '" + result.environment + "'");
        return false;
    }
    if (result.blockCount == 0) {
        SetError(result, "Challenge.Gbx contains no placed blocks: " +
            challengePath);
        return false;
    }
    return true;
}

bool BuildCachePath(
    const fs::path& challengePath,
    const TrackMapLoadOptions& options,
    fs::path& outputPath,
    fs::path& decorationVisualPath,
    TrackMapLoadResult& result) {
    if (options.packsDirectory.empty()) {
        SetError(result, "A Packs directory is required to load Challenge.Gbx");
        return false;
    }
    if (options.extractorProject.empty()) {
        SetError(result,
            "TrackCollisionExtractor.csproj is required to load Challenge.Gbx");
        return false;
    }

    const fs::path packsDirectory(options.packsDirectory);
    const fs::path extractorProject(options.extractorProject);
    const fs::path packList = packsDirectory / "packlist.dat";
    const fs::path stadiumPak = packsDirectory / "Stadium.pak";
    const fs::path extractorSource = extractorProject.parent_path() / "Program.cs";
    uint64_t hash = 14695981039346656037ull;
    std::string errorMessage;
    if (!HashFileIdentity(hash, challengePath, errorMessage) ||
        !HashFileIdentity(hash, packList, errorMessage) ||
        !HashFileIdentity(hash, stadiumPak, errorMessage) ||
        !HashFileIdentity(hash, extractorProject, errorMessage) ||
        !HashFileIdentity(hash, extractorSource, errorMessage)) {
        SetError(result, errorMessage);
        return false;
    }

    fs::path cacheDirectory;
    if (!options.cacheDirectory.empty()) {
        cacheDirectory = options.cacheDirectory;
    } else {
        std::error_code error;
        cacheDirectory = fs::temp_directory_path(error);
        if (error) {
            SetError(result, "Could not determine the system temp directory");
            return false;
        }
        cacheDirectory /= "tmnf-physics-map-cache";
    }
    if (!EnsureDirectory(cacheDirectory, errorMessage)) {
        SetError(result, errorMessage);
        return false;
    }

    std::ostringstream filename;
    filename << SafeStem(challengePath) << '-' << std::hex << std::setfill('0')
             << std::setw(16) << hash << ".tmnfcol";
    outputPath = cacheDirectory / filename.str();
    decorationVisualPath = outputPath;
    decorationVisualPath.replace_extension(".stadium.obj");
    result.collisionCachePath = outputPath.string();
    result.decorationVisualCachePath = decorationVisualPath.string();
    return true;
}

bool ExtractChallengeCollision(
    const fs::path& challengePath,
    const TrackMapLoadOptions& options,
    const fs::path& outputPath,
    const fs::path& decorationVisualPath,
    TrackMapLoadResult& result) {
    std::ostringstream temporarySuffix;
#ifdef _WIN32
    temporarySuffix << ".tmp." << _getpid();
#else
    temporarySuffix << ".tmp." << getpid();
#endif
    const fs::path temporaryPath = outputPath.string() + temporarySuffix.str();
    const fs::path temporaryVisualPath =
        decorationVisualPath.string() + temporarySuffix.str() + ".obj";
    std::error_code ignored;
    fs::remove(temporaryPath, ignored);
    fs::remove(temporaryVisualPath, ignored);

    const std::vector<std::string> arguments = {
        "dotnet", "run", "--no-restore", "--project",
        ExistingAbsolutePath(options.extractorProject), "--",
        ExistingAbsolutePath(challengePath),
        ExistingAbsolutePath(options.packsDirectory),
        temporaryPath.string(),
        "--decoration-visual=" + temporaryVisualPath.string(),
    };
    const int exitCode = RunProcess(arguments);
    if (exitCode != 0) {
        fs::remove(temporaryPath, ignored);
        fs::remove(temporaryVisualPath, ignored);
        SetError(result, "Track collision extractor failed with exit code " +
            std::to_string(exitCode));
        return false;
    }

    GmSurfMesh validationMesh;
    GmSurfMesh validationVisual;
    if (!validationMesh.LoadFromTmnfCollision(temporaryPath.string()) ||
        !validationVisual.LoadFromObj(temporaryVisualPath.string()) ||
        validationVisual.m_vertices.GetCount() == 0u ||
        validationVisual.m_triangles.GetCount() == 0u) {
        fs::remove(temporaryPath, ignored);
        fs::remove(temporaryVisualPath, ignored);
        SetError(result,
            "Extractor produced invalid collision/decoration caches");
        return false;
    }

    fs::rename(temporaryPath, outputPath, ignored);
    if (ignored) {
        // Windows does not replace an existing destination. A competing load
        // may have completed the same cache, so prefer that valid file.
        std::error_code removeError;
        fs::remove(outputPath, removeError);
        ignored.clear();
        fs::rename(temporaryPath, outputPath, ignored);
    }
    if (ignored) {
        fs::remove(temporaryPath, ignored);
        fs::remove(temporaryVisualPath, ignored);
        SetError(result, "Could not publish collision cache: " +
            outputPath.string());
        return false;
    }
    fs::remove(decorationVisualPath, ignored);
    ignored.clear();
    fs::rename(temporaryVisualPath, decorationVisualPath, ignored);
    if (ignored) {
        fs::remove(temporaryVisualPath, ignored);
        SetError(result, "Could not publish decoration visual cache: " +
            decorationVisualPath.string());
        return false;
    }
    return true;
}

} // namespace

bool LoadTrackMapCollision(
    GmSurfMesh& mesh,
    const std::string& mapOrCollisionPath,
    const TrackMapLoadOptions& options,
    TrackMapLoadResult* outputResult,
    GmSurfMesh* decorationVisual) {
    TrackMapLoadResult localResult;
    TrackMapLoadResult& result = outputResult != nullptr
        ? *outputResult
        : localResult;
    result = TrackMapLoadResult{};

    const fs::path inputPath(mapOrCollisionPath);
    if (IsCollisionCachePath(inputPath)) {
        if (!mesh.LoadFromTmnfCollision(mapOrCollisionPath)) {
            SetError(result, "Could not load TMNFCOL1 collision cache: " +
                mapOrCollisionPath);
            return false;
        }
        result.collisionCachePath = mapOrCollisionPath;
        result.cacheHit = true;
        return true;
    }
    if (!IsChallengeGbxPath(inputPath)) {
        SetError(result,
            "Expected a .Challenge.Gbx map or .tmnfcol collision cache: " +
            mapOrCollisionPath);
        return false;
    }

    result.sourceWasChallengeGbx = true;
    const std::string challengePath = ExistingAbsolutePath(inputPath);
    if (!ParseChallenge(challengePath, result)) return false;

    fs::path cachePath;
    fs::path decorationVisualPath;
    if (!BuildCachePath(
            challengePath, options, cachePath, decorationVisualPath, result)) {
        return false;
    }

    const bool cachedCollision = !options.forceCacheRebuild &&
        mesh.LoadFromTmnfCollision(cachePath.string());
    const bool cachedDecoration = decorationVisual == nullptr ||
        decorationVisual->LoadFromObj(decorationVisualPath.string());
    if (cachedCollision && cachedDecoration) {
        result.cacheHit = true;
        return true;
    }
    if (!ExtractChallengeCollision(
            challengePath, options, cachePath, decorationVisualPath, result))
        return false;
    if (!mesh.LoadFromTmnfCollision(cachePath.string())) {
        SetError(result, "Could not load generated collision cache: " +
            cachePath.string());
        return false;
    }
    if (decorationVisual != nullptr &&
        !decorationVisual->LoadFromObj(decorationVisualPath.string())) {
        SetError(result, "Could not load generated Stadium decoration visual: " +
            decorationVisualPath.string());
        return false;
    }
    result.cacheHit = false;
    return true;
}
