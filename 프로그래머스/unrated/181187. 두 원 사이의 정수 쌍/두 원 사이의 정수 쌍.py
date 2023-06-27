import math

def solution(r1, r2):
    answer = 0
    for x in range(r2):
        y_top = math.floor(math.sqrt(r2*r2 - x*x))
        if x < r1:
            y_bottom = math.ceil(math.sqrt(r1*r1 - x*x))
        else:
            y_bottom = 1
        answer += y_top - y_bottom + 1
    return 4*answer