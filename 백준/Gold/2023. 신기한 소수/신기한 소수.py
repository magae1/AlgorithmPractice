from sys import stdin
import math


def is_prime(number: int):
    if number <= 1:
        return False
    elif number <= 3:
        return True
    
    upper_bound: int = math.floor(math.sqrt(number))
    for i in range(2, upper_bound + 1):
        if number % i == 0:
            return False
    return True


def func(target: str, N: int):
    if len(target) > N:
        return
    
    if not is_prime(int(target)):
        return
        
    if len(target) == N:
        print(target)
        return
        
    for num in range(1, 10):
        func(target + str(num), N)

    
N = int(stdin.readline())

fst = ['2', '3', '5', '7']

for f in fst:
    func(f, N)
            