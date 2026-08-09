#ifndef CPLUGSURFACEGEOM_HPP
#define CPLUGSURFACEGEOM_HPP

#include "../Mw/CMwNod.hpp"
#include "../Gm/GmSurf.hpp"
#include "../Classic/CClassicArchive.hpp"

class CPlugSurfaceGeom : public CMwNod {
public:
    // Native CPlugSurfaceGeom stores its polymorphic GmSurf* at +0x34 and
    // its local bounding box at +0x1c. The standalone object owns the
    // surface only when it creates one while loading a GBX.
    GmSurf* m_gmSurf;
    GmBoxAligned m_boundingBox;
    bool m_ownsGmSurf;

    CPlugSurfaceGeom();
    virtual ~CPlugSurfaceGeom();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    GmSurf* GetGmSurf() const;
    GmSurfMesh* GetMesh() const;
    void SetGmSurf(GmSurf* surface, bool takeOwnership = false);
    void Archive(CClassicArchive* archive);
    static CPlugSurfaceGeom* LoadFromGbx(const char* filepath);
};

#endif
