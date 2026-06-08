#ifndef CSYSTEMCRASHDUMP_HPP
#define CSYSTEMCRASHDUMP_HPP

#include "CMwNod.hpp"
class CSystemCrashDump : public CMwNod {
public:
    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
    int IsValid_DumpFidAndMwId(CMwNod* n, const char* str1, const char* str2, CMwNod* n2) { return 0; }
    void StringCatVec3(CMwNod* n, CFastString* s) {}
};

#endif
