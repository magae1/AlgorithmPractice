from sys import stdin

BOARD_SIZE = 19
OFFSETS = [(-1, 1), (0, 1), (1, 1), (1, 0)]

flag = [[[True for _ in range(len(OFFSETS))] for _ in range(BOARD_SIZE)] for _ in range(BOARD_SIZE)]
board = []
starting_points = []
for i in range(BOARD_SIZE):
    board.append(list(map(int, stdin.readline().split())))
    for j in range(BOARD_SIZE):
        if board[i][j] > 0:
            starting_points.append((i, j))
    
result = (0, -1, -1)
starting_points.sort(key=lambda x: (x[1], x[0]))

for point in starting_points:
    i, j = point
    for index, offset in enumerate(OFFSETS):
        offset_i, offset_j = offset
        
        is_succeed = 0
        for n in range(BOARD_SIZE + 1):
            next_i, next_j = i + offset_i*n, j + offset_j*n
            if 0 <= next_i < BOARD_SIZE and 0 <= next_j < BOARD_SIZE \
                    and flag[next_i][next_j][index] \
                    and board[next_i][next_j] == board[i][j]:
                is_succeed += 1
            else:
                break
        
        if is_succeed == 5:
            result = (board[i][j], i, j)
            break
        elif is_succeed > 5:
            for s in range(1, is_succeed):
                flag_i, flag_j = i + offset_i*s, j + offset_j*s
                if 0 <= flag_i < BOARD_SIZE and 0 <= flag_j < BOARD_SIZE:
                    flag[flag_i][flag_j][index] = False
                
    if result[0] > 0:
        break
    
print(result[0])
if result[0] > 0:
    print(f'{result[1] + 1} {result[2] + 1}')
