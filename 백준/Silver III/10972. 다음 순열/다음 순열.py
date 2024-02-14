N = int(input())

nums = [int(n) for n in input().split(' ')]

top_index = -1
for index in range(len(nums) - 1, 0, -1):
    if nums[index - 1] < nums[index]:
        top_index = index
        break

if top_index == -1:
    print(-1)
else:
    sliced_nums = nums[top_index:]
    sliced_nums.sort()
    for i, s in enumerate(sliced_nums):
        if nums[top_index - 1] < s:
            nums[top_index - 1], sliced_nums[i] = sliced_nums[i], nums[top_index - 1]
            break
    result = nums[:top_index] + sliced_nums
    print(*result)
