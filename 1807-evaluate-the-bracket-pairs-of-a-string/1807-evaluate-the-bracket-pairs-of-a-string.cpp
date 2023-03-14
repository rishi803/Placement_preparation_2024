class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string,string>mp;
        
        for(auto &i:knowledge){
            mp[i[0]]=i[1];
        }
        
        string temp;
        string ans;
       bool flag=false;
        
        for(int i=0;i<s.size();i++)
        {
             if(s[i]!='(' and s[i]!=')' and flag==false){
                ans+=s[i];
            }
            
            if(s[i]==')' and flag==true){
                flag=false;
                 // cout<<temp<<" ";
                 if(mp.find(temp)!=mp.end()) ans+=mp[temp];
                 else ans+="?";
                 
                 temp="";
                
            }
            
            if(flag==true){
                temp+=s[i];
            }
            
            if(s[i]=='('){
               
                flag=true;
            }
            
           
            
             
            
            
        } 
        
        return ans;
    }
};