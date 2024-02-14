# 3085 - 사탕 게임

# 동, 남
DIRECTION = [[1, 0], [0, 1]]


def exchange_candy(board, source_x: int, source_y: int, des_x: int, des_y: int):
    tmp = board[des_y][des_x]
    board[des_y][des_x] = board[source_y][source_x]
    board[source_y][source_x] = tmp


def count_candy(board, board_size: int, target_x: int, target_y: int, direction: int):
    max_count = 1
    recent_candy = ''
    if direction == 0:
        count = 1
        for i in range(board_size):
            char: str = board[i][target_x]
            if recent_candy == char:
                count += 1
            else:
                recent_candy = char
                count = 1
            max_count = max(max_count, count)
    else:
        count = 1
        for i in range(board_size):
            char: str = board[target_y][i]
            if recent_candy == char:
                count += 1
            else:
                recent_candy = char
                count = 1
            max_count = max(max_count, count)
    return max_count


def main(board_size: int, board: list[list]):
    maximum_count = 0
    for y in range(board_size):
        for x in range(board_size):
            for index, direc in enumerate(DIRECTION):
                des_x = x + direc[0]
                des_y = y + direc[1]

                if des_x >= board_size or des_y >= board_size:
                    continue

                exchange_candy(board,
                               source_x=x, source_y=y,
                               des_x=des_x, des_y=des_y)

                counts = count_candy(board, board_size, x, y, index)
                maximum_count = max(maximum_count, counts)

                counts = count_candy(board, board_size, x, y, 0 if index == 1 else 1)
                maximum_count = max(maximum_count, counts)

                counts = count_candy(board, board_size, des_x, des_y, index)
                maximum_count = max(maximum_count, counts)

                exchange_candy(board,
                               source_x=x, source_y=y,
                               des_x=des_x, des_y=des_y)

                # if maximum_count is board_size:
                #     return maximum_count
    return maximum_count


if __name__ == '__main__':
    board_size = int(input())
    board = []
    for t in range(board_size):
        board.append(list(input()))

    result = main(board_size, board)
    print(result)


