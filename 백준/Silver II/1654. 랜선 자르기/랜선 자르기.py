import sys


K, N = map(int, input().split())

wires = [int(sys.stdin.readline().rstrip()) for _ in range(K)]

lower, upper = min(wires) // N, max(wires)

result = 1
while True:
    mid = (lower + upper) // 2
    if mid < 2:
        break
    total_count = sum(w // mid for w in wires)
    
    if total_count >= N:
        if lower == mid:
            if upper == mid:
                result = mid
                break
            total_count = sum(w // upper for w in wires)
            if total_count >= N:
                result = upper
                break
            else:
                result = mid
                break
        lower = mid
    else:
        upper = mid - 1
        
print(result)
