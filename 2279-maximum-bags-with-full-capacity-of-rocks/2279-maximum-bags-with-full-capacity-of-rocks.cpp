// store those bags on the top which have less difference in capacity and current rocks present
// make priority queue (min heap)

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int cnt_bags=0;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<rocks.size();i++){
            pq.push(capacity[i]-rocks[i]);
        }
        
        while(!pq.empty()){
            
            int top=pq.top();
            pq.pop();
            
            if(additionalRocks-top>=0){
                additionalRocks-=top;
                top=0;
            }
            
            if(top==0) cnt_bags++;
            
        }
        
       
        return cnt_bags;
    }
};