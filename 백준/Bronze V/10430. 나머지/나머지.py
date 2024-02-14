import sys


def main():
    a, b, c = map(int, sys.stdin.readline().split())

    f = (a + b) % c
    s = ((a % c) + (b % c)) % c
    t = (a * b) % c
    f_1 = ((a % c) * (b % c)) % c
    print('{0}\n{1}\n{2}\n{3}\n'.format(f, s, t, f_1))


if __name__ == '__main__':
    main()
