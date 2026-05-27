#ifndef GMOCTREE_HPP
#define GMOCTREE_HPP


#include "CFastBuffer.hpp"
// #include "CClassicArchive.hpp"
#include "GmBoxAligned.hpp"
#include "GmIso4.hpp"
#include <vector>

// Forward declarations of engine types
class NvStripInfo;
class NvEdgeInfo;
class NvFaceInfo;
template <typename T> class CFastCrypt;

// Assumed 32-byte serialized / 88-byte runtime struct 
// You must define the real fields in your actual SMeshOctreeCell / SColOctreeCell
struct SMeshOctreeCell {
    unsigned long childMask;  // Bitmask of active children
    unsigned long childIndex; // Index into the CFastBuffer for the first child
    unsigned long faceCount;  // Number of faces in this node
    void* faceData;           // Pointer to face list
    GmBoxAligned bounds;      // Bounding box of this node
    // ... padding to 88 bytes as seen in the 0x16 copy loop ...

    void InitEmpty() {
        childMask = 0;
        childIndex = 0xFFFFFFFF; // -1
        faceCount = 0;
        faceData = nullptr;
    }
};

// =================================================
// GmOctree Template
// Inherits from CFastBuffer to store nodes in a contiguous 1D array
// =================================================
template <typename TCell>
class GmOctree : public CFastBuffer<TCell> {
public:
    // =================================================
    // Serialization
    // =================================================
    // void Archive(...) {}

    // =================================================
    // Main Tree Builder
    // =================================================
    void Build(NvStripInfo* stripInfo, std::vector<NvEdgeInfo*>* edges, std::vector<NvFaceInfo*>* faces) {
        // Pseudo-call representing CFastBuffer<SImageHF>::Reset(this)
        this->Reset(); 

        // Allocate the Root Node
        TCell* rootCell = this->AddNewElem();
        rootCell->InitEmpty();

        // The decompiler shows a boolean heuristic check (in_stack_00000014)
        // This typically checks if the bounding box aspect ratio is extreme, 
        // requiring a KD-tree (bintree) split instead of a uniform Octree.
        bool useBintreeFallback = false; // Set to true if aspect ratio heuristic triggers

        if (!useBintreeFallback) {
            BuildOctreeRecurse(this, 0, rootCell, faces);
        } else {
            BuildBintreeRecurse(this, 0, rootCell, faces);
        }

        // Finalize root node with total faces
        // (Translated from the SRpcSkinInfo / SCasterCat pointer math at the end of Build)
        if (this->GetCount() > 0) {
            TCell* finalRoot = &(this->operator[](0));
            finalRoot->faceCount = (unsigned long)faces->size();
        }
    }

    // =================================================
    // 8-Way Recursive Split (Octree)
    // =================================================
    unsigned long BuildOctreeRecurse(GmOctree<TCell>* sourceTree, unsigned long depth, TCell* parentCell, std::vector<NvFaceInfo*>* currentFaces) {
        if (!currentFaces || currentFaces->empty()) return 0;

        // 1. Calculate the bounding box for all faces in this node
        GmBoxAligned parentBounds;
        parentBounds.InitEmpty();
        for (NvFaceInfo* face : *currentFaces) {
            GmBoxAligned faceBounds;
            // Assuming face has a GetBounds() or equivalent
            // face->GetBounds(faceBounds); 
            GmBoxAligned::Union(&parentBounds, &parentBounds, &faceBounds);
        }
        parentCell->bounds = parentBounds;

        // Stop if we hit maximum depth or have only 1 face
        if (currentFaces->size() <= 1 || depth >= 10) {
            parentCell->faceCount = currentFaces->size();
            // Assign faces to leaf node here
            return 1; 
        }

        // 2. Subdivide the parent bounding box into 8 octants
        GmBoxAligned octants[8];
        parentBounds.Subdivide8(octants);

        std::vector<NvFaceInfo*> octantFaces[8];

        // 3. The exact bitwise sorting unrolled in the assembly
        GmIso4 identityMat; 
        identityMat.SetIdentity();

        for (NvFaceInfo* face : *currentFaces) {
            // Again, assuming NvFaceInfo yields a projector or bounds for TestInter
            // CPlugVolumeProjector projector = face->GetProjector();
            unsigned char mask = 0;

            // Assembly exactly mapped: 1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80
            if (GmBoxAligned::TestInter(face, nullptr, &octants[0], &identityMat)) { mask |= 0x01; octantFaces[0].push_back(face); }
            if (GmBoxAligned::TestInter(face, nullptr, &octants[1], &identityMat)) { mask |= 0x02; octantFaces[1].push_back(face); }
            if (GmBoxAligned::TestInter(face, nullptr, &octants[2], &identityMat)) { mask |= 0x04; octantFaces[2].push_back(face); }
            if (GmBoxAligned::TestInter(face, nullptr, &octants[3], &identityMat)) { mask |= 0x08; octantFaces[3].push_back(face); }
            if (GmBoxAligned::TestInter(face, nullptr, &octants[4], &identityMat)) { mask |= 0x10; octantFaces[4].push_back(face); }
            if (GmBoxAligned::TestInter(face, nullptr, &octants[5], &identityMat)) { mask |= 0x20; octantFaces[5].push_back(face); }
            if (GmBoxAligned::TestInter(face, nullptr, &octants[6], &identityMat)) { mask |= 0x40; octantFaces[6].push_back(face); }
            if (GmBoxAligned::TestInter(face, nullptr, &octants[7], &identityMat)) { mask |= 0x80; octantFaces[7].push_back(face); }
        }

        // 4. Recurse for each populated octant
        unsigned long childrenAllocated = 0;
        unsigned long firstChildIndex = this->GetCount();

        for (int i = 0; i < 8; ++i) {
            if (octantFaces[i].empty()) continue;

            // Allocate a new child cell in the contiguous buffer
            TCell* childCell = this->AddNewElem();
            childCell->InitEmpty();
            
            // The famous 0x16 loop (88-byte copy) handled safely
            // Note: In reality, we initialize fresh, but the decompilation showed 
            // a struct copy happening here. We copy the base layout.
            CopyCellData(childCell, parentCell);

            if (octantFaces[i].size() == 1) {
                // Leaf Node optimized assignment
                childCell->faceCount = 1;
                // childCell->faceData = octantFaces[i][0];
                childrenAllocated++;
            } else {
                // Internal Node Recursion
                unsigned long subChildren = BuildOctreeRecurse(sourceTree, depth + 1, childCell, &octantFaces[i]);
                childrenAllocated += subChildren;
            }
        }

        if (childrenAllocated > 0) {
            parentCell->childIndex = firstChildIndex;
            parentCell->childMask = GetPopulatedMask(octantFaces);
        }

        return childrenAllocated;
    }

    // =================================================
    // 2-Way Recursive Split (KD/Bin-Tree Fallback)
    // =================================================
    unsigned long BuildBintreeRecurse(GmOctree<TCell>* sourceTree, unsigned long depth, TCell* parentCell, std::vector<NvFaceInfo*>* currentFaces) {
        if (!currentFaces || currentFaces->empty()) return 0;

        GmBoxAligned parentBounds;
        parentBounds.InitEmpty();
        for (NvFaceInfo* face : *currentFaces) {
            GmBoxAligned faceBounds;
            // face->GetBounds(faceBounds); 
            GmBoxAligned::Union(&parentBounds, &parentBounds, &faceBounds);
        }
        parentCell->bounds = parentBounds;

        if (currentFaces->size() <= 1 || depth >= 10) {
            parentCell->faceCount = currentFaces->size();
            return 1;
        }

        // Subdivide along the longest axis (Bintree split)
        GmBoxAligned childBoxes[2];
        parentBounds.Subdivide2(childBoxes); // Requires implementation in GmBoxAligned

        std::vector<NvFaceInfo*> binFaces[2];
        GmIso4 identityMat; 
        identityMat.SetIdentity();

        for (NvFaceInfo* face : *currentFaces) {
            if (GmBoxAligned::TestInter(face, nullptr, &childBoxes[0], &identityMat)) binFaces[0].push_back(face);
            if (GmBoxAligned::TestInter(face, nullptr, &childBoxes[1], &identityMat)) binFaces[1].push_back(face);
        }

        unsigned long childrenAllocated = 0;
        unsigned long firstChildIndex = this->GetCount();

        for (int i = 0; i < 2; ++i) {
            if (binFaces[i].empty()) continue;

            TCell* childCell = this->AddNewElem();
            childCell->InitEmpty();
            CopyCellData(childCell, parentCell);

            if (binFaces[i].size() == 1) {
                childCell->faceCount = 1;
                childrenAllocated++;
            } else {
                unsigned long subChildren = BuildBintreeRecurse(sourceTree, depth + 1, childCell, &binFaces[i]);
                childrenAllocated += subChildren;
            }
        }

        if (childrenAllocated > 0) {
            parentCell->childIndex = firstChildIndex;
        }

        return childrenAllocated;
    }

private:
    // Helper to replace the hardcoded "iVar5 = 0x16" struct copy loop
    void CopyCellData(TCell* dest, const TCell* src) {
        // Direct memory copy to perfectly emulate the assembly's 88-byte unrolled loop
        // Ensure your TCell is trivially copyable!
        *dest = *src; 
    }

    // Helper to generate the bitmask for the octant
    unsigned long GetPopulatedMask(const std::vector<NvFaceInfo*> octantFaces[8]) {
        unsigned long mask = 0;
        for (int i = 0; i < 8; ++i) {
            if (!octantFaces[i].empty()) {
                mask |= (1 << i);
            }
        }
        return mask;
    }
};

#endif // GMOCTREE_HPP