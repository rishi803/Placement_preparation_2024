class Solution {
public:
    int trap(vector<int>& height) {
        
        int sz= height.size();
        vector<int>prefix(sz);
        vector<int>suffix(sz);
        
        prefix[0]= height[0];
        suffix[sz-1]= height[sz-1];
        
        for(int i=1; i<sz; i++){
            prefix[i]= max(prefix[i-1], height[i]);
        }
        
        for(int i= sz-2; i>=0; i--){
            suffix[i]= max(suffix[i+1], height[i]);
        }
        
        int area= 0;
        
        for(int i=1; i<(sz-1); i++){
            
            if(height[i] < prefix[i] and height[i] < suffix[i]){
            
                int pani= min(prefix[i-1], suffix[i+1]);
                area= area + (pani-height[i]);
            }
            // cout<<height[i]<<" "<<prefix[i]<<" "<<suffix[i]<<endl;
        }
        
        return area;
        
        
    }
};