LOW_Z_ASCII_NUM = 122
ALPHABET_COUNT = 26


def solution(s, skip, index):
    skip_alphabets = {ord(sk) for sk in skip}
    answer = ''
    for char in s:
        i = 1
        char_ascii = ord(char)
        while i <= index:
            char_ascii += 1
            if char_ascii > LOW_Z_ASCII_NUM:
                char_ascii -= ALPHABET_COUNT
            if char_ascii not in skip_alphabets:
                i += 1
        answer += chr(char_ascii)
    return answer
