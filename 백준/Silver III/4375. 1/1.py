# import sys
import math


def main(num):
    size = 0
    offset = 0
    while True:
        mul_sum = 0
        for mul in range(10):
            mul_sum = num * mul + offset
            if mul_sum % 10 == 1:
                break

        offset = math.floor(mul_sum / 10)
        size += 1

        if offset == 0:
            break

    print(size)


if __name__ == '__main__':
    while True:
        try:
            inp = int(input())
            main(inp)
        except EOFError:
            break
            