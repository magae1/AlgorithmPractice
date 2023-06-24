
N = int(input())

A = [int(n) for n in input().split(' ')]
B = [int(n) for n in input().split(' ')]

A.sort(reverse=True)
B.sort()

result = 0
for i in range(N):
    result += A[i] * B[i]

print(result)
