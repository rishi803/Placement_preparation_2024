class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left= k, right=k, ans= nums[k], mn= nums[k], sz= nums.size();
        
        while((left > 0) or (right < sz-1))  // jha khde ho uske left aur right dekho
        {
           if(left == 0 and right < sz-1){  // agr left edge pr ho to na chahte hue right vala lena pdega
                right++;
               mn= min(mn, nums[right]);
              
           }
            
            else if(right == sz-1 and left > 0){ // agr right edge pr ho to na chahte hue left vala lena pdega
                 left--; 
                mn= min(mn, nums[left]);
               
            }
            
            else if ( nums[left-1] > nums[right+1]){  // agr left ke value bdi to idhar hi jao mn ko maximise krne ke liye
                left--;
                mn= min(mn, nums[left]);
            }
            
            else{            // right ki trf jao mn ko maximise krne ke liye
                right++;
                mn= min(mn, nums[right]);
            }
            // cout<<left<<" "<<right<<" "<<mn<<endl;
            ans= max(ans, mn * (right-left+1));
            
        }
        
        return ans;
    }
};