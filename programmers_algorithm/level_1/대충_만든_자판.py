# https://school.programmers.co.kr/learn/courses/30/lessons/160586
from collections import defaultdict


def solution(keymap, targets):
    # key 값을 찾지 못하면 key:100(keymaps의 원소의 최대 크기)으로 자동 삽입하는 defaultdict
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
        # target에 대한 모든 keymapping이 이뤄졌을 때
        if i == len(target):
            answer.append(total_count)
        # target에 대한 모든 keymapping을 하지 못하고 while문을 빠져나왔을 때
        else:
            answer.append(-1)

    return answer


if __name__ == '__main__':
    keymaps = [
        ["ABACD", "BCEFD"],
        ["AA"],
        ["AGZ", "BSSS"],
    ]
    targetses = [
        ["ABCD", "AABB"],
        ["B"],
        ["ASA", "BGZ"],
    ]
    results = [
        [9, 4],
        [-1],
        [4, 6],
    ]
    for trial in range(len(results)):
        ans = solution(keymaps[trial], targetses[trial])
        if ans == results[trial]:
            print(f"{trial}: YES")
        else:
            print(f"{trial}: NO")
