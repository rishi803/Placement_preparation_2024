class Solution {
public:
    
    void help(vector<string>&ans,string digits,vector<string>&mp,int idx,string &temp){
        
        if(idx==digits.size()){     // store the answer
          ans.push_back(temp);
            return;
        }
        
        int num=digits[idx]-'0';   // extract the digit(converting in integer form)
        
        for(int i=0;i<mp[num].size();i++){  // always considering each mp[num] from 0 to its size
           
            temp.push_back(mp[num][i]);  // operation
            
            help(ans,digits,mp,idx+1,temp);
            
            temp.pop_back();
            
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string temp;
        help(ans,digits,mp,0,temp);
        return ans;
    }
};