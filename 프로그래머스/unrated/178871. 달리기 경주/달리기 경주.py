def solution(players, callings):
    players_index = {}
    for i, player in enumerate(players):
        players_index[player] = i
    
    for calling in callings:
        callee_index = players_index[calling]
        callee_front = players[callee_index - 1]
        
        # swap players
        players[callee_index], players[callee_index - 1] = players[callee_index - 1], players[callee_index]
        # swap players_index
        players_index[calling] -= 1
        players_index[callee_front] += 1        
    return players