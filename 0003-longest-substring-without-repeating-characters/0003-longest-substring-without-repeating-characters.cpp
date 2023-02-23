class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char>v(256,0);
        int mx=INT_MIN;
        int i=0,j=0;
        while(j<s.size()){
            if(v[s[j]]==0){
                v[s[j]]++;
                
                mx=max(mx,j-i+1);
               
                j++;
            }
            else{
                while(v[s[j]]!=0)
                { v[s[i]]--;
                i++;}
               
                v[s[j]]++;
                j++;
            }
        }
        return mx==INT_MIN?0:mx;
    }
};