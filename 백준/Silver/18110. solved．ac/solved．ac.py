import sys
import math
from collections import deque


def round_float(f):
    decimal = math.floor(f)
    f -= decimal
    if f >= 0.5:
        return decimal + 1
    return decimal


N = int(input())
cut_num = round_float(N * 0.15)

nums = []
for _ in range(N):
    nums.append(int(sys.stdin.readline()))
nums.sort()
nums = deque(nums)

for _ in range(cut_num):
    nums.pop()
    nums.popleft()

if len(nums) == 0:
    print(0)
else:
    print(round_float(sum(nums) / len(nums)))
    