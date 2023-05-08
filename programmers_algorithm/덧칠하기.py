
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


if __name__ == '__main__':
    n = [
        8,
        5,
        4,
    ]
    m = [
        4,
        4,
        1,
    ]
    sections = [
        [2, 3, 6],
        [1, 3],
        [1, 2, 3, 4],
    ]
    results = [
        2,
        1,
        4,
    ]
    for trial in range(len(n)):
        ans = solution(n[trial], m[trial], sections[trial])
        if ans == results[trial]:
            print(f"{trial}: YES")
        else:
            print(f"{trial}: NO")

