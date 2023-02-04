class Solution {
public:
    string ans;
    vector<string>result;
    
    void help(int n,int k,int cnt){
        
        
        if(ans.size()==n){
               result.push_back(ans);
               return;
        }
      // if(st==n) return;
        
        for(char i='a';i<='c';i++){
           if(ans.size() and ans.back()==i) continue;
            
            ans+=i;
            help(n,k,cnt--);
            ans.pop_back();
        }
       
        
    }
    string getHappyString(int n, int k) {
        help(n,k,n);
       return result.size()<k?"":result[k-1];
    }
};