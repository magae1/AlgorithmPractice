import sys
import math


def main(num: int):
    tmp = num
    total = 0
    while tmp > 0:
        quotient = math.floor(num / tmp)
        total += quotient * tmp
        tmp -= 1
    return total


if __name__ == '__main__':
    n = int(sys.stdin.readline())
    result = main(n)
    print(result)
