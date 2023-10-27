class Solution {
public:
    string longestPalindrome(string s) {
       int n = s.length();
        if (n <= 1) {
            return s;
        }

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n;) {
            int left = i;
            int right = i;

            // Skip identical characters
            while (right < n - 1 && s[right] == s[right + 1]) {
                right++;
            }

            i = right + 1;

            // Expand around the center for odd-length palindromes
            while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }

            // Check if the current palindrome is longer than the previous maxLen
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
        }

        return s.substr(start, maxLen);
    }
};