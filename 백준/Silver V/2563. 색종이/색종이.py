import sys

LENGTH_OF_PAPER = 10
regions = [[0 for _ in range(100)] for _ in range(100)]

for _ in range(int(input())):
    left_offset, bottom_offset = map(int, sys.stdin.readline().split())
    for i in range(left_offset, left_offset + LENGTH_OF_PAPER):
        for j in range(bottom_offset, bottom_offset + LENGTH_OF_PAPER):
            regions[i][j] = 1

result = sum(sum(r) for r in regions)
print(result)
