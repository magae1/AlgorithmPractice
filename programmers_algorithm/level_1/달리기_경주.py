# https://school.programmers.co.kr/learn/courses/30/lessons/178871

def solution(players, callings):
    players_index = {}
    for i, player in enumerate(players):
        players_index[player] = i
    
    for calling in callings:
        callee_index = players_index[calling]
        callee_front = players[callee_index - 1]
        
        # 플레이어 스왑
        players[callee_index], players[callee_index - 1] = players[callee_index - 1], players[callee_index]
        # 플레이어 index도 스왑
        players_index[calling] -= 1
        players_index[callee_front] += 1
    return players


if __name__ == '__main__':
    players = ["mumu", "soe", "poe", "kai", "mine"]
    callings = ["kai", "kai", "mine", "mine"]
    result = ["mumu", "kai", "mine", "soe", "poe"]
    if result == solution(players, callings):
        print("YES")
    else:
        print("NO")
        