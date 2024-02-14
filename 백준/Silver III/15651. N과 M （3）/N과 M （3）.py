import sys


def main(tmp_arr, n, m):
    if len(tmp_arr) is m:
        [print(f'{i} ', end='') for i in tmp_arr]
        print()
        return
    for index in range(1, n + 1):
        tmp_arr.append(index)
        main(tmp_arr, n, m)
        tmp_arr.pop()


if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    arr = []
    main(arr, n, m)

