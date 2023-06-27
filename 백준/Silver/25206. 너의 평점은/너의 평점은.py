import math

score = {
    'A+': 4.5,
    'A0': 4.0,
    'B+': 3.5,
    'B0': 3.0,
    'C+': 2.5,
    'C0': 2.0,
    'D+': 1.5,
    'D0': 1.0,
    'F': 0.0,
}

N = 20
result = 0.0
nums = 0.0
for _ in range(N):
    words = input().split(' ')
    num = float(words[1])
    try:
        result += num * score[words[2]]
        nums += num
    except KeyError:
        pass
    
print(round(result / nums, 6))
