class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<capacity.size();i++){
            pq.push((capacity[i]-rocks[i]));
        }
        int ans=0;
        
        while(!pq.empty()){
            int f=pq.top();
            pq.pop();
           
            if(f>0 and additionalRocks-f>=0){
               additionalRocks-=f;
                f=0;
                
            }
            if(f==0) ans++;
        }
        return ans;
    }
};