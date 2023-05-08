# https://school.programmers.co.kr/learn/courses/30/lessons/161990

EMPTY = '.'
FILE = '#'


def solution(wallpaper):
    min_x, min_y, max_x, max_y = len(wallpaper), len(wallpaper[0]), 0, 0
    for i, line in enumerate(wallpaper):
        for j, char in enumerate(line):
            if char == FILE:
                # 최소 좌표는 좌상단 파일의 위치와 같고, 최대 좌표는 우하단 파일의 위치 (+1,+1)과 같다.
                min_x, min_y = min(min_x, i), min(min_y, j)
                max_x, max_y = max(max_x, i+1), max(max_y, j+1)
    return [min_x, min_y, max_x, max_y]
    

if __name__ == '__main__':
    wallpapers = [
        [".#...", "..#..", "...#."],
        ["..........", ".....#....", "......##..", "...##.....", "....#....."],
        [".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...."],
        ["..", "#."],
    ]
    results = [
        [0, 1, 3, 4],
        [1, 3, 5, 8],
        [0, 0, 7, 9],
        [1, 0, 2, 1],
    ]
    for trial in range(len(wallpapers)):
        ans = solution(wallpapers[trial])
        if ans == results[trial]:
            print(f"{trial}: YES")
        else:
            print(f"{trial}: NO")
    
    