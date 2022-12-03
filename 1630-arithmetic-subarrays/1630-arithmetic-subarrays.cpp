class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0;i<l.size();i++){
            vector<int>temp(nums.begin()+l[i],nums.begin()+r[i]+1);
           int flag=0;
            sort(begin(temp),end(temp));
       
            for(int j=2;j<temp.size();j++){
                if((temp[j]-temp[j-1])!=temp[j-1]-temp[j-2]){
                    flag=1;
                    ans.push_back(false);
                    break;
                };
            }
            if(flag==0)
            ans.push_back(true);
          
        }
        return ans;
    }
};