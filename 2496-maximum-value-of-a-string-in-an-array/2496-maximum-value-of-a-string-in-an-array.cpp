class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans=0,temp;
      
        for(auto it=0;it<strs.size();it++){
              bool flag=true;
            for(int i=0;i<strs[it].size();i++){
                if(isalpha(strs[it][i])){
                    int sz=strs[it].size();
                    ans=max(ans,sz);
                    flag=false;
                    break;
                }
            }
            
         if(flag)  {
             temp=stoi(strs[it]);
             ans=max(ans,temp);
         }
            
        }
        return ans;
    }
};