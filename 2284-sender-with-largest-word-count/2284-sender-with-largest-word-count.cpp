class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int idx=0,cnt=1;
        map<string,int>mp;
        
        for(auto i=0;i<messages.size();i++){
            for(auto j=0;j<messages[i].size();j++){
                if(messages[i][j]==' ') cnt++;
            }
           mp[senders[i]]+=cnt;
            cnt=1;
        }
        vector<pair<string, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(),vec.end(),[]( pair<string,int>&a, pair<string,int>&b){
            if(a.second==b.second) return a.first>b.first;
            else return a.second>b.second;
        });
       
        return vec[0].first;
    }
};