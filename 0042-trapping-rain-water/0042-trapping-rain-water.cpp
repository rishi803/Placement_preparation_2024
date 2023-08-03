class Solution {
public:
    int trap(vector<int>& height) {
        
        int mxleft=height[0],mxright=height[height.size()-1];
        int left=0, right= height.size()-2;
        int ans=0;
        
       while(left<=right)
       {
           if(mxleft < mxright){   // water will trap according to left vala bar
               
               if(height[left] > mxleft) {
                   mxleft= height[left];
               }
               else{
                   ans+= (mxleft - height[left]);
               }
               left++;
           }
           
           else{          // water will trap according to right vala bar
               if(height[right] > mxright) {
                   mxright= height[right];
               }
               else{
                   ans+= (mxright-height[right]);
               }
               right--;
           }
       }
        return ans;
    }
};