class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int idx=0,people_required=costs.size()/2;
        int mincost=0;
        
        priority_queue<pair<int,int>>pq;      // (difference,index_of_element)
        
        for(auto &i:costs){
            
            pq.push({abs(i[0]-i[1]),idx});
            idx++;
        }
        
        int cityA=0,cityB=0;
        
        while(!pq.empty()){
            
            auto cost=pq.top();
            pq.pop();
            
            // cout<<cost.first<<" "<<cost.second<<endl;
            
            int curr_idx=cost.second;
            int cost_cityA=costs[curr_idx][0];
            int cost_cityB=costs[curr_idx][1];
            
            if( cost_cityA < cost_cityB and cityA<people_required){
                cityA++;
                mincost+= cost_cityA;
            }
            else if( cost_cityB <  cost_cityA and cityB<people_required){
                cityB++;
                mincost+= cost_cityB;
            }
            
            else if(cityA == people_required){
               mincost+= cost_cityB;
            }
            
            else if(cityB==people_required){
                mincost+= cost_cityA;
            }
           
            else if(cityA!=people_required and cost_cityA== cost_cityB){
                mincost+=cost_cityA;
                cityA++;
            }
             else if(cityB!=people_required and cost_cityA== cost_cityB){
                mincost+=cost_cityB;
                cityB++;
            }
        }
        return mincost;
    }
};