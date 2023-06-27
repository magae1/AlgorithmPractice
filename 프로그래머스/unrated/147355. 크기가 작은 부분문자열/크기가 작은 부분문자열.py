def solution(t, p):
    answer = 0
    p_length = len(p)
    p_num = int(p)
    for i in range(len(t) - p_length + 1):
        if int(t[i:i + p_length]) <= p_num:
            answer += 1
    return answer