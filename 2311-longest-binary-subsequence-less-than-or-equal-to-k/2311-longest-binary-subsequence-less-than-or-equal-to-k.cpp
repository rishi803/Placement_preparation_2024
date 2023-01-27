class Solution {
public:
 int longestSubsequence(string s, int k) {
        
        int len = floor((float)log2(k))+1;

        if(s.length()<len) return s.length();

        string str = s.substr(s.length()-len);
     
       
        long long num = stoi(str,nullptr,2);
     // cout<<str<<" "<<num<<endl;

        return count(s.begin() , s.begin()+s.length()-len ,'0') + len - (num>k);


    }
};