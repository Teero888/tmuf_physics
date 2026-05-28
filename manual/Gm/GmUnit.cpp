#include "GmUnit.hpp"
#include "CFastString.hpp"

namespace GmUnit {

// =================================================
// Function: GmUnit::ConvertMethodGet
// =================================================
bool ConvertMethodGet(const CFastString& str, EConvertMethod& outMethod) {
    if (str.CompareNoCase("DegToRad") == 0) {
        outMethod = CONVERT_DEGTORAD;
        return true;
    }
    if (str.CompareNoCase("RadToDeg") == 0) {
        outMethod = CONVERT_RADTODEG;
        return true;
    }
    if (str.CompareNoCase("KnotToMs") == 0) {
        outMethod = CONVERT_KNOTTOMS;
        return true;
    }
    if (str.CompareNoCase("MsToKnot") == 0) {
        outMethod = CONVERT_MSTOKNOT;
        return true;
    }
    
    return false;
}

// =================================================
// Function: GmUnit::ConvertReal
// =================================================
float ConvertReal(EConvertMethod method, float value) {
    switch(method) {
        case CONVERT_DEGTORAD:
            return (value * 3.14159265f) / 180.0f; // TODO: lets hope the accuracy is the same as the original
            
        case CONVERT_RADTODEG:
            return (value * 180.0f) / 3.14159265f; // TODO: lets hope the accuracy is the same as the original
            
        case CONVERT_KNOTTOMS:
            return value * 0.51444444f; // 1 Knot = 0.51444... m/s // TODO: lets hope the accuracy is the same as the original
            
        case CONVERT_MSTOKNOT:
            return value * 1.94384449f; // 1 m/s = 1.9438... Knots // TODO: lets hope the accuracy is the same as the original
            
        default:
        case CONVERT_NONE:
            return value;
    }
}

// =================================================
// Function: GmUnit::ConvertRealString
// =================================================
void ConvertRealString(EConvertMethod method, CFastString& inOutStr) {
    if (method != CONVERT_NONE) {
        // Extract float, convert it, and overwrite the string
        float val;
        inOutStr.GetReal(&val);
        val = ConvertReal(method, val);
        inOutStr.SetReal(val);
    }
}

} // namespace GmUnit
