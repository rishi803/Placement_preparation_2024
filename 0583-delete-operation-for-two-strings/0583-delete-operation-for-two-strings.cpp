class Solution {
public:
    char dp[502][502];
    int help(int id1,int id2,string word1,string word2){
     
        if(id1==0) return id2;
        if(id2==0) return id1;
        // if(id1>=word1.size() or id2>=word2.size()) return INT_MAX-100;
        if(dp[id1][id2]!=-1) return dp[id1][id2];
        int option1=INT_MAX,option2=INT_MAX;
        
        if(word1[id1-1]!=word2[id2-1])
            option1=1+min(help(id1-1,id2,word1,word2),help(id1,id2-1,word1,word2));
        else
            option2= help(id1-1,id2-1,word1,word2);
        
        return dp[id1][id2]=min(option1,option2);
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return abs(help(word1.size(),word2.size(),word1,word2));
    }
};