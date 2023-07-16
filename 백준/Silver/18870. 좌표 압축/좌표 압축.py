from sys import stdin

N = int(stdin.readline().rstrip())

coords = [int(c) for c in stdin.readline().split()]
sorted_coords = sorted(set(coords))
coord_map = dict((c, -1) for c in coords)

for i, s_c in enumerate(sorted_coords):
    if coord_map[s_c] == -1:
        coord_map[s_c] = i

for c in coords:
    print(coord_map[c], end=' ')
    