class Solution {
public:
    string frequencySort(string s) {
          int counts[256] = {0};
        for (char ch : s)
            ++counts[ch];
        sort(s.begin(),s.end(),[&](const char a,const char b){
            return counts[a]>counts[b] or (counts[a]==counts[b] and a<b);
        });
            return s;
    }
};