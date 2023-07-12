from sys import stdin

N, M = map(int, stdin.readline().split())

pocketmons_for_name = {}
pocketmons_for_num = []
for n in range(1, N + 1):
    name = stdin.readline().rstrip()
    pocketmons_for_name[name] = n
    pocketmons_for_num.append(name)

results = []
for _ in range(M):
    quiz = stdin.readline().rstrip()
    if quiz.isdigit():
        quiz = int(quiz) - 1
        results.append(pocketmons_for_num[quiz])
        continue
    results.append(pocketmons_for_name[quiz])
    
for r in results:
    print(r, end='\n')
    