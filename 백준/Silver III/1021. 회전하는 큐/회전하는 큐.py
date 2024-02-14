
class RollingQu:
    def __init__(self, N: int):
        self.N = N
        self.flags = [True for _ in range(N)]
        self.plt = 0
    
    def pop_it(self, target):
        self.flags[target] = False
        cur_point = target
        i = 0
        while not self.flags[cur_point] and i <= self.N:
            cur_point += 1
            cur_point = cur_point % self.N
            i += 1
        self.plt = cur_point
    
    def right_roll(self, target):
        cur_point = self.plt
        roll_times = 0
        while target != cur_point or roll_times > self.N:
            cur_point -= 1
            if cur_point < 0:
                cur_point = self.N - 1
            if self.flags[cur_point]:
                roll_times += 1
            
        return roll_times
        
    def left_roll(self, target):
        cur_point = self.plt
        roll_times = 0
        while target != cur_point or roll_times > self.N:
            cur_point += 1
            cur_point = cur_point % self.N
            if self.flags[cur_point]:
                roll_times += 1
            
        return roll_times
    
    def roll(self, target):
        left, right = self.left_roll(target), self.right_roll(target)
        self.pop_it(target)
        return min(left, right)
    
    
N, M = map(int, input().split())
idx = [int(n) - 1 for n in input().split()]

result = 0
q = RollingQu(N)
for i in idx:
    result += q.roll(i)
print(result)
