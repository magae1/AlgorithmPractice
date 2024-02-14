from sys import stdin


N, K = map(int, stdin.readline().split())

bag = [[0 for _ in range(K + 1)] for _ in range(N + 1)]

items = [(0, 0)]
for _ in range(N):
    w, v = map(int, stdin.readline().split())
    items.append((w, v))

for i in range(1, N + 1):
    i_w, i_v = items[i]
    for j in range(1, K + 1):
        rest_w = j - i_w
        if rest_w >= 0:
            bag[i][j] = max(bag[i - 1][j], bag[i - 1][rest_w] + i_v)
            continue
            
        bag[i][j] = bag[i - 1][j]

print(bag[N][K])
    