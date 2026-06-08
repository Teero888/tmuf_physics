min_v = [float('inf')]*3
max_v = [float('-inf')]*3
with open("vehicle_mesh.obj", "r") as f:
    for line in f:
        if line.startswith("v "):
            parts = line.split()
            v = [float(parts[1]), float(parts[2]), float(parts[3])]
            for i in range(3):
                min_v[i] = min(min_v[i], v[i])
                max_v[i] = max(max_v[i], v[i])
print(f"Bounds: min {min_v}, max {max_v}")
