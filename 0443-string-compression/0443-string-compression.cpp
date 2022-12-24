class Solution {
public:
    int compress(vector<char>& chars) {
          if(chars.size()==1) return 1;
           vector<char>temp;
            for(int i=chars.size()-1;i>=0;i--){
                char dummy;
               dummy=chars[i];
                int cnt=1;
                
            while(i>0 and chars[i]==chars[i-1]){
                cnt++;
                 i--;
            }
                string s = to_string(cnt);
                
                if( cnt==1) {
                temp.push_back(dummy);
                    continue;
                }
                
                else
                for(int i=s.size()-1;i>=0;i--){
                    temp.push_back(s[i]);
                }
                
                temp.push_back(dummy);
                
        }
        reverse(temp.begin(),temp.end());
           chars.clear();
           for(int i=0;i<temp.size();i++){
               chars.push_back(temp[i]);
           }
            
      
        return chars.size();
    }
};