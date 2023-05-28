def solution(s):
    answer = 0
    fst_index = 0
    fst_count, other_count = 0, 0
    for index, char in enumerate(s):
        if s[fst_index] == char:
            fst_count += 1
        else:
            other_count += 1
            
        if fst_count == other_count:
            fst_count, other_count = 0, 0
            fst_index = index + 1
            answer += 1
    
    return answer + 1 if fst_index < len(s) else answer