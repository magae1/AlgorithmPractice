from sys import stdin

N, M = map(int, stdin.readline().split())

unheards = set()
for _ in range(N):
    unheards.add(stdin.readline().rstrip())

results = []
for _ in range(M):
    unseen = stdin.readline().rstrip()
    if unseen in unheards:
        results.append(unseen)
    
results.sort()
print(len(results))
for r in results:
    print(r)
    