from collections import defaultdict


def solution(keymap, targets):
    keymap_click = defaultdict(lambda: 100)
    for key in keymap:
        for count, k in enumerate(key):
            keymap_click[k] = min(keymap_click[k], count+1)
        
    answer = []
    for target in targets:
        total_count = 0
        i = 0
        while i < len(target):
            if target[i] not in keymap_click:
                break
            total_count += keymap_click[target[i]]
            i += 1
            
        if i == len(target):
            answer.append(total_count)
        else:
            answer.append(-1)
    
    return answer
