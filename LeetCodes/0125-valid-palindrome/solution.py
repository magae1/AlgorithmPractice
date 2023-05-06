class Solution:
    def isPalindrome(self, s: str) -> bool:
        filtered_deque = collections.deque()
        for char in s:
            if char.isalnum():
                filtered_deque.append(char.lower())
        is_palindrome: bool = True
        while len(filtered_deque) > 1:
            left_char = filtered_deque.popleft()
            right_char = filtered_deque.pop()            
            if left_char != right_char:
                is_palindrome = False
                break
        return is_palindrome
