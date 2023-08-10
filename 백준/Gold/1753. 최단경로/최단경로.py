from sys import stdin
import heapq

UPPER_WEIGHT = 300000*10 + 1

class Node:
    def __init__(self, n: int):
        self.n = n
        self.edges = []
        
    def add_edges(self, w: int, node_idx: int):
        self.edges.append((w, node_idx))
        

V, E = map(int, stdin.readline().split())

nodes = [Node(n) for n in range(V + 1)]
smallest_weights = [UPPER_WEIGHT for _ in range(V + 1)]

start_node_idx = int(stdin.readline())

for _ in range(E):
    u, v, w = map(int, stdin.readline().split())
    nodes[u].add_edges(w, v)
    
pr_qu = []
heapq.heappush(pr_qu, (0, start_node_idx))
smallest_weights[start_node_idx] = 0
while pr_qu:
    cur_w, cur_node_idx = heapq.heappop(pr_qu)
    
    for edge in nodes[cur_node_idx].edges:
        next_w, next_node_idx = edge[0] + cur_w, edge[1]
        if next_w < smallest_weights[next_node_idx]:
            smallest_weights[next_node_idx] = next_w
            heapq.heappush(pr_qu, (next_w, next_node_idx))

for i in range(1, len(smallest_weights)):
    if smallest_weights[i] == UPPER_WEIGHT:
        print('INF')
    else:
        print(smallest_weights[i])
        