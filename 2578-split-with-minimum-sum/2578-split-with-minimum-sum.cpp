class Solution {
public:
    int splitNum(int num) {
        string s=to_string(num);
        sort(s.begin(),s.end());
        string num1,num2;
        
       for(int i = 0; i < s.size(); i = i+2){ num1+=s[i]; }
        for(int i = 1; i < s.size(); i = i+2){ num2+=s[i]; }
        // cout<<num1<<" "<<num2;
        
        long long ans=stol(num1)+stol(num2);
        
        return ans;
        
    }
};