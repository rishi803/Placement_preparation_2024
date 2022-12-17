// map+greedy

class Solution {
public:
    int minDeletions(string s) {
  int ans = 0;
  // count each char
  unordered_map<char, int> char_counts;
  for (const char& c : s) char_counts[c]++;
  unordered_set<int> seen;

  for (auto[k, v] : char_counts) {
    // if we've seen it, decrement it until we haven't
    while (seen.find(v) != seen.end()) {
      v--;
      ans++;
    }
    if (v > 0) seen.insert(v);
  }

  return ans;
}
};