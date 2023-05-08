# https://school.programmers.co.kr/learn/courses/30/lessons/159994

def solution(cards1, cards2, goal):
    # 카드들을 뒤집어 스택으로 만들기(카드 뭉치에서 순서대로 pop하기 위함)
    cards1.reverse()
    cards2.reverse()
    
    for g in goal:
        # 스택의 꼭대기 값 추출. 인덱스 에러(card1의 크기 < 2) 발생 시 패스)
        try:
            deck1_top = cards1[-1]
            if deck1_top == g:
                cards1.pop()
                continue
        except IndexError:
            pass
        # card1과 동일
        try:
            deck2_top = cards2[-1]
            if deck2_top == g:
                cards2.pop()
                continue
        except IndexError:
            pass
        
        return 'No'
    return 'Yes'


if __name__ == '__main__':
    card1s = [
        ["i", "drink", "water"],
        ["i", "water", "drink"],
    ]
    card2s = [
        ["want", "to"],
        ["want", "to"],
    ]
    goals = [
        ["i", "want", "to", "drink", "water"],
        ["i", "want", "to", "drink", "water"],
    ]
    results = [
        "Yes",
        "No",
    ]
    for trial in range(len(results)):
        ans = solution(card1s[trial], card2s[trial], goals[trial])
        if ans == results[trial]:
            print(f"{trial}: YES")
        else:
            print(f"{trial}: NO")
