class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        
        priority_queue<pair<int,int>>pq;
        int ans=0;
        
        for(int i=0;i<reward1.size();i++){
            pq.push({(reward1[i]-reward2[i]),i});
        }
        
        while(!pq.empty()){
            auto to=pq.top();
            pq.pop();
            
            if(k>0)
            ans+=reward1[to.second];
            
            else ans+=reward2[to.second];
            
            // cout<<ans;
            k--;
        }
        
        return ans;
    }
};