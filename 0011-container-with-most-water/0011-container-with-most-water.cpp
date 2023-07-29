class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int area=0;
        
        while(l<r){
            
            area=max(area, min(height[l],height[r]) * (r-l));
            
            if(height[l]>height[r]){
                r--;
            }
            else l++;
        }
        
        return area;
    }
};