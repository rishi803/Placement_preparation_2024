class Solution {
public:
    int trap(vector<int>& height) {
        
        int sz= height.size();
        vector<int>suffix(sz);
        suffix[sz-1]= 0;
        int mxx= 0;
        for(int i= sz-2; i>=0; i--){
             mxx= max(mxx,height[i+1]);
            suffix[i]= mxx;
        }
        
        int water=0, mx=height[0];
        
        for(int i=1; i<height.size(); i++){
            
            mx= max(mx,height[i]);
            
            if(height[i] < mx and height[i] < suffix[i]) water+= (min(mx,suffix[i]) - height[i]); // this water only be counted if its value is less than left boundary (mx) and rightboundary (suffix[i])
            
            // cout<<suffix[i]<<" "<<height[i]<<" "<<water<<endl;
        }
        
        return water;
    }
};