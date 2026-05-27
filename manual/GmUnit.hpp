#ifndef GMUNIT_HPP
#define GMUNIT_HPP

#include <cstdint>

class CFastString;

enum EConvertMethod {
    CONVERT_NONE     = 0,
    CONVERT_DEGTORAD = 1,
    CONVERT_RADTODEG = 2,
    CONVERT_KNOTTOMS = 3,
    CONVERT_MSTOKNOT = 4
};

namespace GmUnit {
    // String parsing
    bool ConvertMethodGet(const CFastString& str, EConvertMethod& outMethod);
    
    // Core math conversions
    float ConvertReal(EConvertMethod method, float value);
    
    // In-place string conversion
    void ConvertRealString(EConvertMethod method, CFastString& inOutStr);
};

#endif // GMUNIT_HPP