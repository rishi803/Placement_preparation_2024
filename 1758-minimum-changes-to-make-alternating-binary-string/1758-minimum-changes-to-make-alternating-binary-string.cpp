class Solution {
public:
    int minOperations(string s) {
        int ans= 0;
        int cnt= 0;
        
        for(int i=0; i<s.size(); i++){
            
            if(i%2==0){
                if(s[i] != '1') cnt++;
            }
            else{
                if(s[i] != '0') cnt++;
            }
        }
        
        ans= cnt;
        cnt= 0;
        
        for(int i=0; i<s.size(); i++){
            if(i%2 != 0){
                if(s[i] != '1') cnt++;
            }
            else{
                if(s[i] != '0') cnt++;
            }
        }
        
        ans= min(ans, cnt);
        return ans;
    }
};