import re

with open("tuning29.txt", "r") as f:
    lines = f.readlines()

curves = {}
current_curve = None
parsing_xs = False
parsing_ys = False

for i, line in enumerate(lines):
    line_str = line.rstrip()
    if line_str.endswith(":") and not line_str.startswith(" ") and not "Chunk" in line_str:
        current_curve = line_str[:-1]
        curves[current_curve] = {"Xs": [], "Ys": [], "Interp": "Linear"}
    elif current_curve:
        if line_str.strip() == "Xs:":
            parsing_xs = True
            parsing_ys = False
        elif line_str.strip() == "Ys:":
            parsing_ys = True
            parsing_xs = False
        elif "RealInterp = " in line_str:
            curves[current_curve]["Interp"] = line_str.split("=")[1].strip()
            parsing_xs = False
            parsing_ys = False
        elif line_str.startswith("  ") and not line_str.startswith("   "):
            parsing_xs = False
            parsing_ys = False
        elif parsing_xs:
            val = line_str.strip()
            if val and not "chunk" in val.lower():
                curves[current_curve]["Xs"].append(val)
        elif parsing_ys:
            val = line_str.strip()
            if val and not "chunk" in val.lower():
                curves[current_curve]["Ys"].append(val)

print("--- GENERATED CPP ---")
for k, v in curves.items():
    if not v["Xs"] or not v["Ys"]: continue
    xs = ", ".join(v["Xs"]) + ","
    ys = ", ".join(v["Ys"]) + ","
    xs = xs.replace(",", "f, ")
    ys = ys.replace(",", "f, ")
    print(f"inline float {k}_times[] = {{ {xs[:-2]} }};")
    print(f"inline float {k}_values[] = {{ {ys[:-2]} }};")

print("\n--- InitCurve calls ---")
for k, v in curves.items():
    if not v["Xs"] or not v["Ys"]: continue
    print(f"    InitCurve({k}, {len(v['Xs'])}, {k}_times, {k}_values);")

