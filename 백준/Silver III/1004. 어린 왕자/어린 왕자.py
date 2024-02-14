import math


class Center:
    def __init__(self, cx, cy, r):
        self.cx = cx
        self.cy = cy
        self.r = r
    
    def is_in_system(self, x, y):
        d = math.sqrt((self.cx - x) ** 2 + (self.cy - y) ** 2)
        return d > self.r


T = int(input())

for _ in range(T):
    x1, y1, x2, y2 = map(int, input().split(' '))
    result = 0
    N = int(input())
    for _ in range(N):
        cx, cy, r = map(int, input().split(' '))
        cen = Center(cx, cy, r)
        
        f1, f2 = cen.is_in_system(x1, y1), cen.is_in_system(x2, y2)
        if (f1 and not f2) or (not f1 and f2):
            result += 1
        
    print(result)
    
    