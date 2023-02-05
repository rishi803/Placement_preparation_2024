class Solution {
public:
    bool vowel(char x){
        if(x=='a' or x=='e' or x=='o' or x=='i' or x=='u') return true;
        else return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<long long>pre(n,0);
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            int last=words[i].size()-1;
            if(i==0 and vowel(words[i][0]) and vowel(words[i][last])) pre[0]=1;
            else if (vowel(words[i][0]) and vowel(words[i][last])) pre[i]+=pre[i-1]+1;
            else if(i>0) pre[i]+=pre[i-1];
        }
     
        
        // for(auto it:pre) cout<<it<<endl;
        
        for(auto &it:queries){
            int f=it[0];
            int s=it[1];
            
            if(f!=0){
                int res= pre[s]-pre[f-1];
                ans.push_back(res);
            }
            else ans.push_back(pre[s]);
            
        }
        return ans;
    }
};