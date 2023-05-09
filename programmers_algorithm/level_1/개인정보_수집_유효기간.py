# https://school.programmers.co.kr/learn/courses/30/lessons/150370
"""
날짜를 숫자로 변환하여 비교
"""
MIN_YEAR = 2000
MAX_MONTH = 12
MAX_DAY = 28


def solution(today, terms, privacies):
    today = sum([(int(today[0:4])-MIN_YEAR) * MAX_MONTH * MAX_DAY,
                 int(today[5:7]) * MAX_DAY,
                 int(today[8:10])])
    term_hash = {term[0]: int(term[2:]) for term in terms}
        
    answer = []
    for index, privacy in enumerate(privacies):
        privacy_time = sum([(int(privacy[0:4])-MIN_YEAR) * MAX_MONTH * MAX_DAY,
                            int(privacy[5:7]) * MAX_DAY,
                            int(privacy[8:10])])
        privacy_type = privacy[-1]
        passing_time = term_hash[privacy_type] * MAX_DAY
        if privacy_time + passing_time <= today:
            answer.append(index + 1)
        
    return answer


if __name__ == '__main__':
    todays = [
        "2022.05.19",
        "2020.01.01",
    ]
    termses = [
        ["A 6", "B 12", "C 3"],
        ["Z 3", "D 5"],
    ]
    privacieses = [
        ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"],
        ["2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"],
    ]
    results = [
        [1, 3],
        [1, 4, 5],
    ]
    for trial in range(len(results)):
        ans = solution(todays[trial], termses[trial], privacieses[trial])
        print(ans)
        if ans == results[trial]:
            print(f"{trial}: YES")
        else:
            print(f"{trial}: NO")
