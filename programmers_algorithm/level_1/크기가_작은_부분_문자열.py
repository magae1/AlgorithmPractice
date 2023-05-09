# https://school.programmers.co.kr/learn/courses/30/lessons/147355

def solution(t, p):
    answer = 0
    p_length = len(p)
    p_num = int(p)
    for i in range(len(t) - p_length + 1):
        if int(t[i:i + p_length]) <= p_num:
            answer += 1
    return answer


if __name__ == '__main__':
    t = [
        "3141592",
        "500220839878",
        "10203",
    ]
    p = [
        "271",
        "7",
        "15",
    ]
    results = [
        2,
        8,
        3,
    ]
    for trial in range(len(results)):
        ans = solution(t[trial], p[trial])
        if ans == results[trial]:
            print(f"{trial}: YES")
        else:
            print(f"{trial}: NO")
