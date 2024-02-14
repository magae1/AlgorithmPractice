from sys import stdin

N, M = map(int, input().split())
arr = []

fst = [0 for _ in range(N)]
for i, s in enumerate(stdin.readline().split()):
    s = int(s)
    if i == 0:
        fst[0] = s
        continue
    fst[i] = fst[i - 1] + s
arr.append(fst)

for row in range(1, N):
    temp = [0 for _ in range(N)]
    for col, s in enumerate(stdin.readline().split()):
        s = int(s)
        if col == 0:
            temp[0] = arr[row - 1][0] + s
            continue
        temp[col] = arr[row - 1][col] + temp[col - 1] - arr[row - 1][col - 1] + s
    arr.append(temp)

results = []
for _ in range(M):
    x1, y1, x2, y2 = map(int, stdin.readline().split())
    x1, y1, x2, y2 = x1 - 2, y1 - 2, x2 - 1, y2 - 1
    
    result = arr[x2][y2]
    if x1 >= 0 and y1 >= 0:
        result += arr[x1][y1]
    if x1 >= 0:
        result -= arr[x1][y2]
    if y1 >= 0:
        result -= arr[x2][y1]
    results.append(result)
    
for r in results:
    print(r, end='\n')
