class Solution {
public:
    
    static bool comp(const string a, const string b){
       return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        
        vector<string>copy;
        
        for(int i=0;i<nums.size();i++){
            copy.push_back(to_string(nums[i]));
        }
        
        sort(copy.begin(),copy.end(),comp);
        
        string ans,temp;
        
        
        for(auto &i:copy){
            ans+=i;
        }
        bool flag=0;
        
        for(int i=0;i<ans.size();i++){
            if(i==0){
                while(ans[i]=='0'){
                    flag=1;
                    i++;
                }
            }
            else{
                temp+=ans[i];
                flag=1;
            }
        }
        if(temp.empty() and flag==1) return "0";
        if(flag==1 and ans[0]=='0') return temp;
        return ans;
    }
};