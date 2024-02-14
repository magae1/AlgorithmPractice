import sys


TARGET = 100
NUM_OF_DWARF = 9
IS_END = False


def res_func(index_of_heights, sum_of_heights, heights, picked):
    global IS_END
    if sum_of_heights > TARGET:
        return
    if sum_of_heights == TARGET and len(picked) == 7:
        IS_END = True
        return

    for index in range(index_of_heights, NUM_OF_DWARF):
        selected_height = heights[index]
        picked.append(selected_height)
        res_func(index + 1, sum_of_heights + selected_height, heights, picked)
        if IS_END:
            return
        picked.pop()


def main(heights):
    picked = []
    res_func(0, 0, heights, picked)
    return picked


if __name__ == '__main__':
    heights = []
    for i in range(NUM_OF_DWARF):
        height = int(sys.stdin.readline())
        heights.append(height)

    res = main(heights)
    res.sort()
    for r in res:
        print(r)

