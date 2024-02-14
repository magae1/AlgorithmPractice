from sys import stdin


for _ in range(int(input())):
    ops = list(stdin.readline().rstrip())
    front_D, back_D = 0, 0
    num_of_R = 0
    is_front = True
    for op in ops:
        if op == 'R':
            is_front = not is_front
            num_of_R += 1
        else:
            if is_front:
                front_D += 1
            else:
                back_D += 1
    
    num_of_R = num_of_R % 2
    n = int(stdin.readline())
    arr = stdin.readline().rstrip()
    if n == 0:
        arr = []
    else:
        arr = arr[1:-1].split(sep=',')
    
    if front_D + back_D > n:
        print('error')
    else:
        arr = arr[front_D:len(arr)-back_D]
        if num_of_R == 1:
            arr.reverse()
        print(f'[{",".join(arr)}]')
    