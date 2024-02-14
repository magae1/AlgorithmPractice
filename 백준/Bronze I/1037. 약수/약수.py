import sys
import math


def main(nums_size: int, input_nums: list[int]):
    input_nums.sort()
    if nums_size % 2 == 1:
        mid = input_nums[math.floor(nums_size / 2)]
        return mid * mid

    fst = input_nums[0]
    lst = input_nums[nums_size - 1]
    return fst * lst


if __name__ == '__main__':
    size = int(sys.stdin.readline())
    nums = list(map(int, sys.stdin.readline().split()))
    result = main(size, nums)
    print(result)
