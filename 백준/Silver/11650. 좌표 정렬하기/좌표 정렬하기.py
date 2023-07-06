import sys


dots = []
for i in range(int(input())):
    dots.append(tuple(map(int, sys.stdin.readline().split())))
    
dots.sort()
for d in dots:
    print(f'{d[0]} {d[1]}')
    