#include "CMwDeprecated.hpp"
#include "CClassicArchive.hpp"

// =================================================
// Function: CMwDeprecated::Chunk
// Skips legacy, deprecated chunks in the data stream by 
// reading (or writing) dummy values to maintain byte alignment.
// =================================================
void CMwDeprecated::Chunk(CFuncSegment* segment, CClassicArchive* archive, uint32_t chunkId) 
{
    if (chunkId == 0x09063000) {
        uint8_t dummy8 = 0;
        uint32_t dummy32 = 0;
        
        archive->DoNat8(&dummy8, 1);
        archive->DoNatural(&dummy32, 1);
        
        // Loop of 5 (20 bytes of legacy padding)
        for (int i = 0; i < 5; ++i) {
            uint32_t dummyPadding = 0;
            archive->DoNatural(&dummyPadding, 1);
        }
    } 
    else if (chunkId == 0x09063001) {
        uint8_t dummy8 = 0;
        uint32_t dummy32 = 0;
        
        archive->DoNat8(&dummy8, 1);
        archive->DoNatural(&dummy32, 1);
        
        for (int i = 0; i < 5; ++i) {
            uint32_t dummyPadding = 0;
            archive->DoNatural(&dummyPadding, 1);
        }
    } 
    else if (chunkId == 0x09063002) {
        uint32_t dummyData1 = 0;
        uint32_t dummyData2 = 0;
        
        // DoData handles raw byte blocks (4 bytes here)
        archive->DoData(&dummyData1, 4);
        archive->DoNatural(&dummyData2, 1);
        
        for (int i = 0; i < 5; ++i) {
            uint32_t dummyPadding = 0;
            archive->DoNatural(&dummyPadding, 1);
        }
    }
}

// =================================================
// Function: CMwDeprecated::WrapClassId
// Massive routing table converting legacy Class IDs into 
// their modern Nadeo Engine equivalents.
// =================================================
uint32_t CMwDeprecated::WrapClassId(uint32_t classId) 
{
    switch (classId) {
        // Base / Early Engine Conversions
        case 0x0900D000: return 0x0900F000;
        case 0x09063000: return 0x09026000;
        case 0x0307B000: return 0x03078000;
        
        // 0x24... Block / Item / Script Conversions
        case 0x24003000: return 0x03043000;
        case 0x24004000: return 0x03033000;
        case 0x24005000: return 0x0304E000;
        case 0x24006000: return 0x03036000;
        case 0x24007000: return 0x03057000;
        case 0x24008000: return 0x03058000;
        case 0x24009000: return 51200000; // 0x030D4000 in hex
        case 0x2400A000: return 0x0301A000;
        case 0x2400B000: return 0x03044000;
        case 0x2400C000: return 0x0305B000;
        case 0x2400D000: return 0x0301F000;
        case 0x2400E000: return 0x0301D000;
        case 0x2400F000: return 0x0301E000;
        case 0x24011000: return 0x0305A000;
        case 0x24012000: return 0x030D1000;
        case 0x24019000: return 0x030CE000;
        case 0x2401A000: return 0x03039000;
        case 0x2401B000: return 0x03092000;
        case 0x2401C000: return 0x0305C000;
        case 0x2401D000: return 0x0305D000;
        case 0x2401E000: return 0x0305E000;
        case 0x2401F000: return 0x03038000;
        case 0x24020000: return 0x0304F000;
        case 0x24021000: return 0x03050000;
        case 0x24022000: return 0x03051000;
        case 0x24023000: return 0x03052000;
        case 0x24024000: return 0x03053000;
        case 0x24025000: return 0x03054000;
        case 0x24027000: return 0x0302D000;
        case 0x24028000: return 0x030CB000;
        case 0x24029000: return 0x03055000;
        case 0x2402A000: return 0x030BB000;
        case 0x2402B000: return 0x030D2000;
        case 0x2402C000: return 0x0305F000;
        case 0x2402D000: return 0x0307E000;
        case 0x24033000: return 0x030D3000;
        case 0x24034000: return 0x0308D000;
        case 0x24038000: return 0x03090000;
        case 0x24039000: return 0x0308F000;
        case 0x2403A000: return 0x03059000;
        case 0x2403B000: return 0x030CC000;
        case 0x2403C000: return 0x0301B000;
        case 0x2403E000: return 0x0301C000;
        case 0x2403F000: return 0x03093000;
        case 0x24040000: return 0x0303B000;
        case 0x24046000: return 0x03035000;
        case 0x24047000: return 0x03047000;
        case 0x24048000: return 0x030AF000;
        case 0x24049000: return 0x030E0000;
        case 0x2404A000: return 0x0308C000;
        case 0x2404D000: return 0x0308A000;
        case 0x2404E000: return 0x03002000;
        case 0x2404F000: return 0x03073000;
        case 0x24050000: return 0x0303A000;
        case 0x24052000: return 0x030AE000;
        case 0x24053000: return 0x030C9000;
        case 0x24054000: return 0x03045000;
        case 0x24059000: return 0x030B8000;
        case 0x2405A000: return 0x03080000;
        case 0x2405D000: return 0x030B1000;
        case 0x2405E000: return 0x03086000;
        case 0x2405F000: return 0x03081000;
        case 0x24061000: return 0x03078000;
        case 0x24062000: return 0x03078000;
        case 0x24063000: return 0x03087000;
        case 0x24064000: return 0x03056000;
        case 0x24065000: return 0x0307F000;
        case 0x24066000: return 0x03085000;
        case 0x24067000: return 0x030A2000;
        case 0x24068000: return 0x030A8000;
        case 0x24069000: return 0x0307C000;
        case 0x2406A000: return 0x03077000;
        case 0x2406B000: return 0x03082000;
        case 0x2406C000: return 0x030B2000;
        case 0x2406D000: return 0x03084000;
        case 0x2406F000: return 0x030A7000;
        case 0x24070000: return 0x030A0000;
        case 0x24071000: return 0x0308B000;
        case 0x24072000: return 0x03094000;
        case 0x24073000: return 0x030CD000;
        case 0x24075000: return 0x030A9000;
        case 0x24076000: return 0x03079000;
        case 0x24077000: return 0x0307A000;
        case 0x2407A000: return 0x030A1000;
        case 0x2407B000: return 0x030B3000;
        case 0x2407C000: return 0x030B4000;
        case 0x2407D000: return 0x030B5000;
        case 0x24081000: return 0x030A5000;
        case 0x24082000: return 0x030AA000;
        case 0x24083000: return 0x030AB000;
        case 0x24084000: return 0x030A3000;
        case 0x24088000: return 0x030A4000;
        case 0x24089000: return 0x030A6000;
        case 0x2408A000: return 0x030AD000;
        case 0x2408B000: return 0x0309F000;
        case 0x24091000: return 0x0307D000;
        case 0x24094000: return 0x030AC000;
        case 0x24095000: return 0x03095000;
        case 0x24097000: return 0x030DE000;
        case 0x24098000: return 0x030DF000;
        case 0x24099000: return 0x0309A000;
        case 0x2409A000: return 0x030BC000;
        case 0x2409B000: return 0x03048000;
        case 0x240A0000: return 0x0308E000;
        case 0x240A1000: return 0x030BE000;
        case 0x240A2000: return 0x0309B000;
        case 0x240A3000: return 0x0309C000;
        case 0x240A4000: return 0x030B9000;
        case 0x240A5000: return 0x030BA000;
        case 0x240A6000: return 0x030BF000;
        case 0x240A8000: return 0x030BD000;
        case 0x240A9000: return 0x030DB000;
        case 0x240AB000: return 0x0303C000;
        case 0x240AC000: return 0x030C1000;
        case 0x240AD000: return 0x03096000;
        case 0x240AE000: return 0x03097000;
        case 0x240AF000: return 0x030C3000;
        case 0x240B0000: return 0x030C4000;
        case 0x240B1000: return 0x030D0000;
        case 0x240B2000: return 0x030D7000;
        case 0x240B3000: return 0x030C6000;
        case 0x240B4000: return 0x030CF000;
        case 0x240B6000: return 0x030C0000;
        case 0x240B7000: return 0x030DC000;
        case 0x240B8000: return 0x03098000;
        case 0x240B9000: return 0x030B6000;
        case 0x240BA000: return 0x030B7000;
        case 0x240BB000: return 0x030C5000;
        case 0x240BC000: return 0x030D8000;
        case 0x240BD000: return 0x03046000;
        case 0x240C0000: return 0x03089000;
        case 0x240C1000: return 0x030DD000;
        case 0x240C2000: return 0x030D6000;
        case 0x240C3000: return 0x030C8000;
        case 0x240C5000: return 0x030D5000;
        case 0x240C7000: return 0x03088000;
        case 0x240C8000: return 0x030D9000;
        case 0x240C9000: return 0x03099000;
        case 0x240CA000: return 0x030CA000;
        case 0x240CB000: return 0x030C2000;
        case 0x240CC000: return 0x03091000;
        case 0x240CD000: return 0x030DA000;
        case 0x240CE000: return 0x030C7000;
        case 0x240CF000: return 0x03083000;

        default:
            // Return unchanged if not deprecated
            return classId; 
    }
}