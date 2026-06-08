#ifndef CPLUGSURFACEGEOM_HPP
#define CPLUGSURFACEGEOM_HPP

#include "../Mw/CMwNod.hpp"
#include "../Gm/GmSurf.hpp"
#include "../Classic/CClassicArchive.hpp"

class CPlugSurfaceGeom : public CMwNod {
public:
    GmSurfMesh* m_mesh;
    GmBoxAligned m_boundingBox;

    CPlugSurfaceGeom();
    virtual ~CPlugSurfaceGeom();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    void Archive(CClassicArchive* archive);
    static CPlugSurfaceGeom* LoadFromGbx(const char* filepath);
};

#endif
