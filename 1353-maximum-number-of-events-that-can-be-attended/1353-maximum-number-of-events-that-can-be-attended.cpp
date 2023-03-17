class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(),events.end());
        int ans=0;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int days=0,i=0;
        
        for(days=1;days<=100000;days++){
            
            
            while(i<events.size() and events[i][0]==days){
                pq.push(events[i][1]);
                i++;
            }
            
            while(!pq.empty() and pq.top()<days){
                pq.pop();
            }
            
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
        }
        
        return ans;
    }
};