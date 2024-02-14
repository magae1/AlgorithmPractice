from sys import stdin


N = int(stdin.readline())
scores = [[0 for _ in range(2)] for _ in range(N + 1)]

stair = [0]

for i in range(1, N + 1):
    stair.append(int(stdin.readline()))
    
    scores[i][0] = stair[i]
    scores[i][1] = scores[i - 1][0] + stair[i]
    if i >= 2:
        scores[i][0] += max(scores[i - 2])
    
print(max(scores[N]))
