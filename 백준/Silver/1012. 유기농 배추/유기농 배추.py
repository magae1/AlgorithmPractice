from queue import Queue

offsets = [(1, 0), (0, 1), (-1, 0), (0, -1)]
T = int(input())
qu = Queue()

for _ in range(T):
    M, N, K = map(int, input().split(' '))
    field = [[0 for _ in range(M)] for _ in range(N)]
    
    positions = []
    for _ in range(K):
        x, y = map(int, input().split(' '))
        field[y][x] = 1
        positions.append((x, y))
    
    result = 0
    for pos in positions:
        x, y = pos
        if field[y][x] == 0:
            continue
    
        qu.put(pos)
        result += 1
        field[y][x] = 0
        while not qu.empty():
            front_x, front_y = qu.get()
            for offset_x, offset_y in offsets:
                next_x, next_y = offset_x + front_x, offset_y + front_y
                if 0 <= next_x < M and 0 <= next_y < N and field[next_y][next_x] == 1:
                    field[next_y][next_x] = 0
                    qu.put((next_x, next_y))
    
    print(result)
    