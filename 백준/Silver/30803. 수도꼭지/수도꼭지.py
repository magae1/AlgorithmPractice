from sys import stdin

n = int(input())

taps = [int(i) for i in stdin.readline().split()]
flags = [True for _ in range(n)]
sum_taps = sum(taps)
results = [sum_taps]

for _ in range(int(input())):
    commands = list(map(int, stdin.readline().split()))
    
    if commands[0] == 1:
        idx_of_tap, value = commands[1] - 1, commands[2]
        if flags[idx_of_tap]:
            sum_taps -= taps[idx_of_tap]
            sum_taps += value
        taps[idx_of_tap] = value
    else:
        idx_of_tap = commands[1] - 1
        if flags[idx_of_tap]:
            sum_taps -= taps[idx_of_tap]
        else:
            sum_taps += taps[idx_of_tap]
        flags[idx_of_tap] = not flags[idx_of_tap]
        
    results.append(sum_taps)
    
for r in results:
    print(r)
    
    