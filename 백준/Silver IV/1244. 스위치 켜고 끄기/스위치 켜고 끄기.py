from sys import stdin

MALE = 1
FEMALE = 2


num_of_switches = int(stdin.readline())
switches = [0] + [state for state in map(int, stdin.readline().split())]

num_of_students = int(stdin.readline())
for _ in range(num_of_students):
    sex, num = map(int, stdin.readline().split())
    
    if sex == MALE:
        for i in range(1, num_of_switches//num + 1):
            switches[num * i] = 0 if switches[num * i] else 1
    else:
        switches[num] = 0 if switches[num] else 1
        offset = 1
        while True:
            front, back = num - offset, num + offset
            if 1 > front or back > num_of_switches or switches[front] != switches[back]:
                break
                
            if switches[back] == 1:
                switches[front], switches[back] = 0, 0
            else:
                switches[front], switches[back] = 1, 1
            offset += 1
                
for i in range(1, num_of_switches + 1):
    print(switches[i], end=' ')
    
    if i % 20 == 0:
        print()
    