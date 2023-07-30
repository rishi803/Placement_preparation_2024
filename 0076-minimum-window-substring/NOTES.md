https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
​
// unordered_map<char, int> m;
// vector<int> m(128, 0);
int m[128] = {};
​
// Storing all characters into a map...
for(char i : t) m[i]++;
​
// Counter: Stores how many characters we need to make a valid window
int i = 0, j = 0, start = 0, len = INT_MAX, counter = t.size(), n = s.size();
// check for every valid index...
while(j < n){
// if the current element exists in t: then the counter will decrease...
if(m[s[j]] > 0) counter--;
​
// if the current element doesn't exist in t: then m[s[j]] will be negative: if it exists, then it can be positive...
m[s[j]]--;
​
// If you found the valid window...
while(counter == 0){
if(len > j - i + 1){
len = j - i + 1;
start = i;
}
​
// Shrinking: Window
// If s[i] exist in the target string then, it will be perfect zero... now, after increment, it will become +ve
// If s[i] doesn't exist in the target string, then its already will be negative: as it was never incremented in first for "for loop" before while one.
// Also, it was decremented in the while loop. So, m[s[i]] will surely be negative.
// But s[i] which exist in the target string will become positive. As we skipped the s[i] character so we will increment the counter as we need s[i] later to make a valid window.
m[s[i]]++;
​
// If m[s[i]] becomes positive, only we will increase the counter.... as we are sliding the window.
if(m[s[i]] > 0) counter++;
i++;
}
j++;
}
return len == INT_MAX ? "" : s.substr(start, len);