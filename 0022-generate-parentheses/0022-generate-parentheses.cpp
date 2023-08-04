class Solution {
public:
    
    vector<string>ans;
    
    void help(int open, int close, string &temp){
        if(close < open) return;
        
        if(open==0 and close==0){
            ans.push_back(temp);
            return;
        }
       
        if(open > 0){
            temp+='(';
            help(open-1, close, temp);
            temp.pop_back();
        }
        
        if(close > 0){
            temp+=')';
            help(open, close-1, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=n,close=n;
        string temp;
        
        help(open,close,temp);
        
        return ans;
    }
};