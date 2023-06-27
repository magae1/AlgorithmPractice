EMPTY = '.'
FILE = '#'


def solution(wallpaper):
    min_x, min_y, max_x, max_y = len(wallpaper), len(wallpaper[0]), 0, 0
    for i, line in enumerate(wallpaper):
        for j, char in enumerate(line):
            if char == FILE:
                min_x, min_y = min(min_x, i), min(min_y, j)
                max_x, max_y = max(max_x, i+1), max(max_y, j+1)
    return [min_x, min_y, max_x, max_y]
