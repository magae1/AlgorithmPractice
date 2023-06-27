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