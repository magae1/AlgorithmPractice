def solution(n, m, section):
    wall = [True for _ in range(n+1)]
    for num in section:
        wall[num] = False
    
    answer = 0
    current_index = 1
    while current_index <= n:
        if not wall[current_index]:
            answer += 1
            current_index += m
        else:
            current_index += 1
    
    return answer