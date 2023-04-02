class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int>temp(26,1001);
        int mx=0,sum=0;
        
        for(auto i=0;i<chars.size();i++){
            temp[chars[i]-'a']=vals[i];
        }
        
        for(int i=0;i<s.size();i++){
           
            if(temp[s[i]-'a']==1001) sum+=s[i]-'a'+1;
            else sum+=temp[s[i]-'a'];
            
            mx=max(mx,sum);
            
            if(sum<0) sum=0;
            
            
        }
        return mx;
        
    }
};