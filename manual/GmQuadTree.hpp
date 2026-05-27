#ifndef GMQUADTREE_HPP
#define GMQUADTREE_HPP

#include "CFastBuffer.hpp"
#include "GmVec2.hpp"
#include <vector>
#include <algorithm>
#include <cstdint>

// Forward declarations
class NvFaceInfo;
class CCrystalFace;

// Reverse-engineered 24-byte struct based on the 'puVar11 + 6' copying loop.
// 6 * 4 bytes = 24 bytes.
struct SQuadTreeMeshUv {
    uint32_t childIndex; // 0x00 - Index to first child in CFastBuffer (0xFFFFFFFF if leaf)
    uint32_t elementCount; // 0x04 - Number of faces/UVs in this node
    GmVec2 minBounds;         // 0x08 - 2D Bounding Box Min (X, Y)
    GmVec2 maxBounds;         // 0x10 - 2D Bounding Box Max (X, Y)

    void InitEmpty() {
        childIndex = 0xFFFFFFFF;
        elementCount = 0;
        minBounds = { 1e30f, 1e30f }; // Init to max float
        maxBounds = { -1e30f, -1e30f }; // Init to min float
    }
};

// =================================================
// GmQuadTree Template
// Inherits from CFastBuffer to store nodes contiguously
// =================================================
template <typename TCell>
class GmQuadTree : public CFastBuffer<TCell> {
public:
    // =================================================
    // 2-Way Recursive Split (Kd-Tree approach for QuadTree)
    // =================================================
    uint32_t BuildBintreeRecurse(GmQuadTree<TCell>* sourceTree, 
                                      std::vector<CCrystalFace*>* currentFaces, 
                                      uint32_t depth) 
    {
        if (!currentFaces || currentFaces->empty()) {
            return 0;
        }

        // 1. Calculate 2D Bounding Box (Collapses the MSVC unrolled pfVar13 loop)
        GmVec2 minB = { 1e30f, 1e30f };
        GmVec2 maxB = { -1e30f, -1e30f };

        for (CCrystalFace* face : *currentFaces) {
            GmVec2 faceMin, faceMax;
            // Assuming CCrystalFace has a way to get 2D UV bounds
            // face->GetUvBounds(faceMin, faceMax);
            
            if (faceMin.x < minB.x) minB.x = faceMin.x;
            if (faceMin.y < minB.y) minB.y = faceMin.y;
            if (faceMax.x > maxB.x) maxB.x = faceMax.x;
            if (faceMax.y > maxB.y) maxB.y = faceMax.y;
        }

        // Allocate the current node
        TCell* parentCell = this->AddNewElem();
        parentCell->InitEmpty();
        parentCell->minBounds = minB;
        parentCell->maxBounds = maxB;

        // 2. Termination Check
        // If we have very few elements or hit max depth, create a leaf node
        if (currentFaces->size() <= 1 || depth >= 10) { // Depth limit heuristic
            parentCell->elementCount = currentFaces->size();
            // In a real engine, you'd store the actual face pointers/indices here
            return 1; 
        }

        // 3. Find the longest axis to split (Kd-tree style bisection)
        float sizeX = maxB.x - minB.x;
        float sizeY = maxB.y - minB.y;
        
        bool splitX = (sizeX > sizeY);
        float splitPlane = splitX ? (minB.x + sizeX * 0.5f) : (minB.y + sizeY * 0.5f);

        // 4. Partition the geometry into Left and Right lists
        std::vector<CCrystalFace*> leftFaces;
        std::vector<CCrystalFace*> rightFaces;

        for (CCrystalFace* face : *currentFaces) {
            GmVec2 faceCenter;
            // face->GetUvCenter(faceCenter);
            
            float centerVal = splitX ? faceCenter.x : faceCenter.y;
            
            if (centerVal < splitPlane) {
                leftFaces.push_back(face);
            } else {
                rightFaces.push_back(face);
            }
        }

        // Failsafe: if all faces fell on one side due to floating point precision,
        // force a half-and-half split to prevent infinite recursion
        if (leftFaces.empty() || rightFaces.empty()) {
            size_t half = currentFaces->size() / 2;
            leftFaces.assign(currentFaces->begin(), currentFaces->begin() + half);
            rightFaces.assign(currentFaces->begin() + half, currentFaces->end());
        }

        uint32_t childrenAllocated = 0;
        uint32_t firstChildIndex = this->GetCount();

        // 5. Recurse Left
        if (!leftFaces.empty()) {
            // Memory preservation trick: We use an index instead of a pointer 
            // because AddNewElem() might reallocate the CFastBuffer array!
            uint32_t subChildren = BuildBintreeRecurse(sourceTree, &leftFaces, depth + 1);
            childrenAllocated += subChildren;
        }

        // 6. Recurse Right
        if (!rightFaces.empty()) {
            uint32_t subChildren = BuildBintreeRecurse(sourceTree, &rightFaces, depth + 1);
            childrenAllocated += subChildren;
        }

        // Re-fetch parentCell because 'this->AddNewElem()' in children might have invalidated the pointer
        parentCell = &(this->operator[](firstChildIndex - 1));

        if (childrenAllocated > 0) {
            parentCell->childIndex = firstChildIndex;
            parentCell->elementCount = currentFaces->size();
        }

        // Return total nodes created in this sub-branch (1 for parent + children)
        return childrenAllocated + 1;
    }

private:
    // Helper to replace the hardcoded "iVar9 = 6" undefined4 copy loops
    void CopyCellData(TCell* dest, const TCell* src) {
        // Direct memory copy to emulate the 24-byte unrolled assembly assignment
        *dest = *src;
    }
};

#endif // GMQUADTREE_HPP