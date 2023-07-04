import sys


N, M = map(int, input().split())

nums = [int(_) for _ in input().split()]
for i in range(1, N):
    nums[i] = nums[i] + nums[i - 1]

results = []
for _ in range(M):
    start, end = map(int, sys.stdin.readline().split())
    start, end = start - 2, end - 1
    if start < 0:
        results.append(nums[end])
    else:
        results.append(nums[end] - nums[start])

for r in results:
    print(r)
