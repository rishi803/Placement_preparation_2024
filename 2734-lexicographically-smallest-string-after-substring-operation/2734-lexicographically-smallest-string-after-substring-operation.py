class Solution:
    def smallestString(self, s):
        s = list(s)  # Convert the string to a list of characters for efficient updates
        start = 0
        while start < len(s) and s[start] == 'a':
            start += 1  # Skip if 'a' is occurring as a substring from the starting
        if start == len(s):  # If reaches the end, we have to do exactly 1 operation, so just change the last character
            s[-1] = 'z'
        for i in range(start, len(s)):
            if s[i] == 'a':
                return ''.join(s)  # Convert the list back to a string
            else:
                s[i] = chr(ord(s[i]) - 1)  # Replace non-'a' characters with the previous character
        return ''.join(s)  # Convert the list back to a string
