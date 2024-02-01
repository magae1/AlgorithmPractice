from sys import stdin

N, K = map(int, stdin.readline().split())

string = str(input())

left_bound, right_bound, up_bound, down_bound = 0, 0, 0, 0
x_pos, y_pos = 0, 0

for s in string:
    if s == 'U':
        y_pos += 1
        up_bound = max(up_bound, y_pos)
    elif s == 'D':
        y_pos -= 1
        down_bound = min(down_bound, y_pos)
    elif s == 'L':
        x_pos -= 1
        left_bound = min(left_bound, x_pos)
    elif s == 'R':
        x_pos += 1
        right_bound = max(right_bound, x_pos)

flag = False
x_pos, y_pos = 0, 0

for _ in range(K):
    for s in string:
        if s == 'U':
            y_pos += 1
        elif s == 'D':
            y_pos -= 1
        elif s == 'L':
            x_pos -= 1
        elif s == 'R':
            x_pos += 1
            
        if x_pos == 0 and y_pos == 0:
            flag = True
            break
    
    if flag or not (y_pos + down_bound <= 0 <= y_pos + up_bound and x_pos + left_bound <= 0 <= x_pos + right_bound):
        break

if flag:
    print("YES")
else:
    print("NO")