using System;
using System.IO;
using System.Linq;
using GBX.NET;
using GBX.NET.LZO;
using GBX.NET.Engines.Plug;
using GBX.NET.Engines.Function;

namespace ExtractTuning {
    class Program {
        static void DumpFunc(StreamWriter fw, string name, dynamic func) {
            if (func == null || func.Xs == null || func.Ys == null) {
                fw.WriteLine($"// {name} is null");
                return;
            }
            var xs = (System.Collections.Generic.IEnumerable<float>)func.Xs;
            var ys = (System.Collections.Generic.IEnumerable<float>)func.Ys;
            
            var xStr = string.Join(", ", xs.Select(x => x.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) + "f"));
            var yStr = string.Join(", ", ys.Select(y => y.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) + "f"));
            
            fw.WriteLine($"float {name}_times[] = {{ {xStr} }};");
            fw.WriteLine($"float {name}_values[] = {{ {yStr} }};");
            fw.WriteLine($"CFuncKeysReal {name} = {{ {xs.Count()}, {name}_times, {name}_values }};");
            fw.WriteLine();
        }

        static void PrintChunks(StreamWriter fw, CPlugVehiclePhyTuning tun) {
            fw.WriteLine("// Chunks:");
            foreach (var chunk in tun.Chunks) {
                fw.WriteLine($"//   0x{chunk.Id:X8}");
            }
        }

        static void Main(string[] args) {
            Gbx.LZO = new MiniLZO();
            var node = Gbx.ParseNode("../StadiumCar.VehicleTunings.Gbx");
            
            using (var fw = new StreamWriter("../TuningData.hpp")) {
                fw.WriteLine("#pragma once");
                fw.WriteLine("struct CFuncKeysReal { int count; float* times; float* values; };");
                fw.WriteLine("struct CSceneVehicleCarTuningData {");
                fw.WriteLine("    CFuncKeysReal* m_maxSideFriction;");
                fw.WriteLine("    CFuncKeysReal* m_steerDriveTorque;");
                fw.WriteLine("    CFuncKeysReal* m_steerSlowDown;");
                fw.WriteLine("    CFuncKeysReal* m_lateralContactSlowDown;");
                fw.WriteLine("    float m_maxSideFrictionSliding;");
                fw.WriteLine("};");
                fw.WriteLine();
                
                if (node is CPlugVehiclePhyTunings tunings) {
                    dynamic tun = tunings.Tuning[0];
                    DumpFunc(fw, "MaxSideFriction", tun.MaxSideFriction);
                    DumpFunc(fw, "SteerDriveTorque", tun.SteerDriveTorque);
                    DumpFunc(fw, "SteerSlowDown", tun.SteerSlowDown);
                    DumpFunc(fw, "LateralContactSlowDown", tun.LateralContactSlowDown);
                    DumpFunc(fw, "AccelCurve", tun.AccelCurve);
                    
                    fw.WriteLine($"float MaxSideFrictionSliding = {tun.MaxSideFrictionSliding}f;");
                    
                    fw.WriteLine("// ALL PROPERTIES:");
                    foreach (var prop in ((object)tun).GetType().GetProperties()) {
                        try {
                            fw.WriteLine($"//   {prop.Name} = {prop.GetValue((object)tun)}");
                        } catch {
                            fw.WriteLine($"//   {prop.Name} = <error>");
                        }
                    }
                    
                    PrintChunks(fw, tun);
                    
                    fw.WriteLine();
                    fw.WriteLine("void InitTuningData(CSceneVehicleCarTuningData* data) {");
                    fw.WriteLine("    data->m_maxSideFriction = &MaxSideFriction;");
                    fw.WriteLine("    data->m_steerDriveTorque = &SteerDriveTorque;");
                    fw.WriteLine("    data->m_steerSlowDown = &SteerSlowDown;");
                    fw.WriteLine("    data->m_lateralContactSlowDown = &LateralContactSlowDown;");
                    fw.WriteLine("    data->m_maxSideFrictionSliding = MaxSideFrictionSliding;");
                    fw.WriteLine("}");
                }
            }
            Console.WriteLine("Generated TuningData.hpp");
        }
    }
}
