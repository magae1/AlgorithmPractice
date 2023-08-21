import sys


DIRECTIONS = [
    (0, 1),     # 동
    (0, -1),    # 서
    (1, 0),     # 남
    (-1, 0),    # 북
]
R, C = map(int, sys.stdin.readline().split())

board = [[char for char in sys.stdin.readline().rstrip()] for _ in range(R)]
alpha_flag = [False for _ in range(26)]

# position = (r, c)
# (position, direction idx)
stk = [((0, 0), -1)]
alpha_flag[ord(board[0][0]) - 65] = True
max_visited = 0

while len(stk) > 0:
    cur_pos, next_dir = stk.pop()
    while next_dir <= 3:
        next_r, next_c = (cur_pos[0] + DIRECTIONS[next_dir][0], cur_pos[1] + DIRECTIONS[next_dir][1])
        
        if 0 <= next_r < R and 0 <= next_c < C and not alpha_flag[ord(board[next_r][next_c]) - 65]:
            stk.append((cur_pos, next_dir + 1))
            cur_pos, next_dir = (next_r, next_c), 0
            
            alpha_flag[ord(board[next_r][next_c]) - 65] = True
            max_visited = max(max_visited, len(stk))
            if max_visited == 25:
                break
            continue
        next_dir += 1
        
    alpha_flag[ord(board[cur_pos[0]][cur_pos[1]]) - 65] = False
    
print(max_visited + 1)
    