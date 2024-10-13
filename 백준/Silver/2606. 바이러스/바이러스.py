from collections import deque


class Computer:
    def __init__(self):
        self.adjust_coms = []
        self.visited = False
    
    def add_adjust_node(self, computer):
        self.adjust_coms.append(computer)
    

N = int(input())
computers = [Computer() for num in range(N + 1)]

for _ in range(int(input())):
    fst, sec = map(int, input().split())
    computers[fst].add_adjust_node(computers[sec])
    computers[sec].add_adjust_node(computers[fst])
    
result = 0
deq = deque()
deq.append(computers[1])
computers[1].visited = True
while len(deq) > 0:
    cur_com = deq.popleft()
    for ad_com in cur_com.adjust_coms:
        if not ad_com.visited:
            ad_com.visited = True
            deq.append(ad_com)
            result += 1
            
print(result)
