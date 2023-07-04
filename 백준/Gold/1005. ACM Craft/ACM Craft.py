import sys
from sys import stdin
from collections import defaultdict
sys.setrecursionlimit(2000)


def dp(buildings, total_times, edges, index):
    if total_times[index] > -1:
        return total_times[index]
    
    max_time = -1
    for next_b in edges[index]:
        max_time = max(max_time,
                       dp(buildings, total_times, edges, next_b) + buildings[index])
    total_times[index] = max_time
    return max_time
    
    
T = int(input())

for _ in range(T):
    N, K = map(int, stdin.readline().split())
    
    buildings = [0] + [int(time) for time in stdin.readline().split()]
    total_con_times = [-1 for _ in range(len(buildings))]
    is_leaf = [True for _ in range(N + 1)]
    edges = defaultdict(list)
    for _ in range(K):
        start, end = map(int, stdin.readline().split())
        edges[end].append(start)
        is_leaf[end] = False
    
    for i in range(1, N + 1):
        if is_leaf[i]:
            total_con_times[i] = buildings[i]
    W = int(input())
    print(dp(buildings, total_con_times, edges, W))
    