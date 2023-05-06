class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) < 2 or s == s[::-1]:
            return s

        sut_length = len(s)
        result = s[0]
        for index in range(0, sut_length):
            for i in range(1, sut_length):
                left_index = index - i
                right_index = index + i
                if 0 > left_index or right_index >= sut_length or s[left_index] is not s[right_index]:
                    break
                temp_result = s[left_index:right_index+1]
                if len(result) < len(temp_result):
                    result = temp_result
            
            for j in range(1, sut_length):
                left_index = index - (j - 1)
                right_index = index + j
                if 0 > left_index or right_index >= sut_length or s[left_index] is not s[right_index]:
                    break
                temp_result = s[left_index:right_index+1]
                if len(result) < len(temp_result):
                    result = temp_result
            
        return result
