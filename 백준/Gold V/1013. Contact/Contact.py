
T = int(input())

for _ in range(T):
    stream = [*input()]
    
    is_valid = True
    cur_state = 0
    for c in stream:
        if cur_state == 0:
            if c == '0':
                cur_state = 1
            else:
                cur_state = 2
        elif cur_state == 1:
            if c == '1':
                cur_state = 0
            else:
                is_valid = False
        elif cur_state == 2:
            if c == '0':
                cur_state = 3
            else:
                is_valid = False
        elif cur_state == 3:
            if c == '0':
                cur_state = 4
            else:
                is_valid = False
        elif cur_state == 4:
            if c == '1':
                cur_state = 5
        elif cur_state == 5:
            if c == '1':
                cur_state = 6
            else:
                cur_state = 1
        elif cur_state == 6:
            if c == '0':
                cur_state = 7
        elif cur_state == 7:
            if c == '0':
                cur_state = 4
            else:
                cur_state = 0
        if not is_valid:
            break
    
    if not (cur_state == 0 or cur_state == 5 or cur_state == 6):
        is_valid = False
    print("YES" if is_valid else "NO")
    