# https://school.programmers.co.kr/learn/courses/30/lessons/172928

START, ROAD, OBSTACLE = 'S', 'O', 'X'
NORTH, SOUTH, WEST, EAST = 'N', 'S', 'W', 'E'


def MoveLegalRoute(park, direction, move_size, current_position):
    moving_positions = []
    # N 방향으로 이동 시
    if direction == NORTH:
        moving_positions = [[current_position[0] - step, current_position[1]] for step in range(1, move_size+1)]
    # S 방향으로 이동 시
    elif direction == SOUTH:
        moving_positions = [[current_position[0] + step, current_position[1]] for step in range(1, move_size + 1)]
    # W 방향으로 이동 시
    elif direction == WEST:
        moving_positions = [[current_position[0], current_position[1] - step] for step in range(1, move_size + 1)]
    # E 방향으로 이동 시
    else:
        moving_positions = [[current_position[0], current_position[1] + step] for step in range(1, move_size + 1)]
    
    # 주어진 방향으로 이동할 때 공원을 벗어나는지 확인
    moved_position_x, moved_position_y = moving_positions[-1]
    if not(0 <= moved_position_x < len(park) and 0 <= moved_position_y < len(park[0])):
        return
    
    # 주어진 방향으로 이동 중 장애물을 만나는지 확인
    for move_position in moving_positions:
        step_x, step_y = move_position
        if park[step_x][step_y] == OBSTACLE:
            return
    current_position[0], current_position[1] = moving_positions[-1]


def solution(park, routes):
    divided_park = []
    current_position = [0, 0]
    for i, p in enumerate(park):
        arr = []
        for j, char in enumerate(p):
            if char == START:
                current_position[0], current_position[1] = i, j
            arr.append(char)
        divided_park.append(arr)
    
    for route in routes:
        direction, move_size = route.split()
        MoveLegalRoute(park, direction, int(move_size), current_position)
    return current_position


if __name__ == '__main__':
    parks = [
        ["SOO", "OOO", "OOO"],
        ["SOO", "OXX", "OOO"],
        ["OSO", "OOO", "OXO", "OOO"],
    ]
    routeses = [
        ["E 2", "S 2", "W 1"],
        ["E 2", "S 2", "W 1"],
        ["E 2", "S 3", "W 1"],
    ]
    results = [
        [2, 1],
        [0, 1],
        [0, 0],
    ]
    
    for trial in range(len(parks)):
        ans = solution(parks[trial], routeses[trial])
        if ans == results[trial]:
            print(f"{trial}: YES")
        else:
            print(f"{trial}: NO")
    