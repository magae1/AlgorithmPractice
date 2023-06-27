def solution(cards1, cards2, goal):
    cards1.reverse()
    cards2.reverse()
    
    for g in goal:
        try:
            deck1_top = cards1[-1]
            if deck1_top == g:
                cards1.pop()
                continue
        except IndexError:
            pass
        
        try:
            deck2_top = cards2[-1]
            if deck2_top == g:
                cards2.pop()
                continue
        except IndexError:
            pass
        
        return 'No'
    return 'Yes'