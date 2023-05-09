# https://school.programmers.co.kr/learn/courses/30/lessons/155652
"""
주의 사항
while문 안에 있는 if문의 위치가 바뀔 경우,
a를 스킵해야 할 때 제대로 작동하지 않음.
"""

LOW_Z_ASCII_NUM = 122
ALPHABET_COUNT = 26


def solution(s, skip, index):
    # 스킵할 알파벳 아스키 코드 해시 테이블
    skip_alphabets = {ord(sk) for sk in skip}
    answer = ''
    for char in s:
        i = 1
        char_ascii = ord(char)
        while i <= index:
            char_ascii += 1
            # 바꾼 알파벳의 아스키 코드가 z를 넘어갈 때
            if char_ascii > LOW_Z_ASCII_NUM:
                char_ascii -= ALPHABET_COUNT
            # 바꾼 알파벳의 아스키 코드가 스킵 알파벳의 아스키 코드일 때
            if char_ascii not in skip_alphabets:
                i += 1
        answer += chr(char_ascii)
    return answer


if __name__ == '__main__':
    ss = [
        "aukks",
    ]
    skips = [
        "wbqd",
    ]
    indexes = [
        5,
    ]
    results = [
        "happy",
    ]
    for trial in range(len(results)):
        ans = solution(ss[trial], skips[trial], indexes[trial])
        if ans == results[trial]:
            print(f"{trial}: YES")
        else:
            print(f"{trial}: NO")
