import sys
from functools import cmp_to_key


def cmp(x1, x2):
    if len(x1) == len(x2):
        for i in range(len(x1)):
            if x1[i] != x2[i]:
                return (x1[i] > x2[i]) - (x1[i] < x2[i])
    return (len(x1) > len(x2)) - (len(x1) < len(x2))
    

N = int(input())
words = set()
for _ in range(N):
    words.add(sys.stdin.readline().rstrip())

words = list(words)
words.sort(key=cmp_to_key(cmp))

for word in words:
    print(word)
    