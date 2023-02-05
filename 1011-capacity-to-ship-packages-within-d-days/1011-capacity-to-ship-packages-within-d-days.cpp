class Solution {
public:
    int help(vector<int>&weights,int wt,int days){
       int cnt=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>wt){
                cnt++;
                sum=weights[i];
            }
        }
        if(cnt<=days) return true;
        else return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int high=accumulate(weights.begin(),weights.end(),0);
        int low=*max_element(weights.begin(),weights.end());
        int ans=0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (help(weights,mid, days)) {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        return ans;
    }
};