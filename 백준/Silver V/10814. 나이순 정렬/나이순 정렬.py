import sys


people = []
for i in range(int(input())):
    age, name = sys.stdin.readline().split()
    age = int(age)
    people.append((age, i, name))
    
people.sort()
for p in people:
    print(f'{p[0]} {p[2]}')
    