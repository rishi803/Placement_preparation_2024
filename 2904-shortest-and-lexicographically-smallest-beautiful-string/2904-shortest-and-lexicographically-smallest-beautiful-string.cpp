class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

  // Find length of shortest beautiful substring
  int len = n + 1; 
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = i; j < n; j++) {
      if (s[j] == '1') count++;
      if (count == k) {
        len = min(len, j - i + 1);
        break;
      }
    }
  }

  if (len > n) return ""; // No beautiful substring

  // Find lexicographically smallest substring of length len
  string ans = "";
  for (int i = 0; i <= n - len; i++) {
    string sub = s.substr(i, len);
    if (count(sub.begin(), sub.end(), '1') == k) {
      if (ans.empty() || sub < ans) ans = sub; 
    }
  }
  return ans;
    }
};