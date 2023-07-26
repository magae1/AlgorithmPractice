from sys import stdin


N = int(stdin.readline())

coords = []
for _ in range(N):
    x, y = map(int, stdin.readline().split())
    coords.append((x, y))

coords.sort(key=lambda c: (c[1], c[0]))

for coord in coords:
    print('{} {}'.format(coord[0], coord[1]))
    