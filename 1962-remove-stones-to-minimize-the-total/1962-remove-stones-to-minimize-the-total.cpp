class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
        // creating max heap
        priority_queue<int>pq(piles.begin(),piles.end());
        while(k--){
            int top=pq.top();
            pq.pop();
          
            top=(top+1)/2;
             
            pq.push(top);
        }
        while(!pq.empty()){
            
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};