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
