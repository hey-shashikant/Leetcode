class Solution:
    def isValid(self, s: str) -> bool:
        stack = deque()
        for char in s:
            if char == '{' or char == '[' or char == '(':
                stack.append(char)
            elif len(stack) > 0 and char == '}' and stack[-1] == '{':
                stack.pop()
            elif len(stack) > 0 and char == ')' and stack[-1] == '(':
                stack.pop()
            elif len(stack) > 0 and char == ']' and stack[-1] == '[':
                stack.pop()
            else:
                return False
        
        return len(stack) == 0
            