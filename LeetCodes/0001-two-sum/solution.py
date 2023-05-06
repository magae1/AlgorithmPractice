class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_obj = {}
        for index, num in enumerate(nums):
            nums_obj[num] = index
        
        for i in range(len(nums)):
            num = nums[i]
            temp_target = target - num
            if temp_target in nums_obj and i is not nums_obj[temp_target]:
                return [i, nums_obj[temp_target]]
                
