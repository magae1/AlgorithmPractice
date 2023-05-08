# https://school.programmers.co.kr/learn/courses/30/lessons/176963
def solution(name, yearning, photo):
    name_obj = {n: index for index, n in enumerate(name)}
    
    answer = []
    for single_photo in photo:
        total_yearning = 0
        for photo_member in single_photo:
            try:
                member_index = name_obj[photo_member]
            except KeyError:
                continue
            member_yearning = yearning[member_index]
            total_yearning += member_yearning
        answer.append(total_yearning)
    return answer


if __name__ == '__main__':
    names = [
        ["may", "kein", "kain", "radi"],
        ["kali", "mari", "don"],
        ["may", "kein", "kain", "radi"],
    ]
    yearnings = [
        [5, 10, 1, 3],
        [11, 1, 55],
        [5, 10, 1, 3],
    ]
    photos = [
        [["may", "kein", "kain", "radi"], ["may", "kein", "brin", "deny"], ["kon", "kain", "may", "coni"]],
        [["kali", "mari", "don"], ["pony", "tom", "teddy"], ["con", "mona", "don"]],
        [["may"], ["kein", "deny", "may"], ["kon", "coni"]],
    ]
    results = [
        [19, 15, 6],
        [67, 0, 55],
        [5, 15, 0],
    ]
    
    for i in range(len(names)):
        ans = solution(names[i], yearnings[i], photos[i])
        if ans == results[i]:
            print(f"{i}: YES")
        else:
            print(f"{i}: NO")
