class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        bool ans=false;
        int j=0;
        
        for(int i=0; i<s.size(); i++){
            
            if(s.size() % (i+1)==0){
                
                 string temp= "a",temp2="b";
            
            for(j=i+1; j<s.size()-i; j+=i+1){
                
                temp= s.substr(0,i+1);
                temp2=s.substr(j,i+1);
                
                 // cout<<"t ="<<temp<<" ";
                // cout<<temp2<<" ";
                if(temp != temp2) break;
                 
            }
            // cout<<j<<endl;
            if(j==s.size() and temp == temp2) return true;
            // cout<<endl;
        }
    }
            
          
        
        return ans;
    }
};