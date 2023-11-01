class Solution {
public:
    
    bool isvalid(vector<int>&pos, int balls, int midforce){
        int cnt = 1;
        int force= pos[0]+midforce;
        
        for(int i=1; i<pos.size(); i++){
            
            if(pos[i] >= force){
                cnt++;
                force= pos[i] + midforce;
            }
        }
        
        return cnt >= balls;
    }
    
    int maxDistance(vector<int>& position, int m) {
        
       sort(position.begin(),  position.end());
       int sz= position.size();
        
        int low= 1;
        int high= position[sz-1] - position[0];
        int ans= 0;
        
        while(low <= high){
            int mid= low + (high-low)/2;
            
            if(isvalid(position,m,mid)){
                ans= mid;
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        
        return ans;
    }
};