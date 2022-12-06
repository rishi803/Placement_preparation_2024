class Solution {
public:
    int countSubstrings(string s) {
       int count = 0;
    
    // Iterate over each character in the string
    for (int i = 0; i < s.length(); i++) {
        // Iterate over each possible length of the substring
        for (int j = 1; i + j <= s.length(); j++) {
            // Check if the characters at the beginning and end of the substring
            // are the same
            if (s[i] == s[i+j-1]) {
                // Check if the substring starting at i and with length j
                // is a palindrome
                bool isPalindrome = true;
                for (int k = 0; k < j / 2; k++) {
                    if (s[i+k] != s[i+j-k-1]) {
                        isPalindrome = false;
                        break;
                    }
                }
                // If it is, increment the counter
                if (isPalindrome) {
                    count++;
                }
            }
        }
    }

    // Return the total number of palindromes
    return count;
    }
};