class Solution {
public:
    int minNumberOfFrogs(string cro) {
        string temp="croak";
        unordered_map<char,int>index;
        unordered_map<char,int>freq;
        
        int ans=0,frogs=0;
        index['c']=0,index['r']=1,index['o']=2,index['a']=3,index['k']=4;
        
        for(int i=0;i<cro.size();i++){
            
            if(cro[i]=='c') freq[cro[i]]++;
            else{
                int idx=index[cro[i]];
                if(freq[temp[idx-1]]<=freq[cro[i]]) return -1;
                else{
                    freq[cro[i]]++;
                }
            }
            
            if(cro[i]=='c') frogs++;
            if(cro[i]=='k') frogs--;
            
            ans=max(ans,frogs);
        }
        
        return frogs!=0?-1:ans;
        
    }
};