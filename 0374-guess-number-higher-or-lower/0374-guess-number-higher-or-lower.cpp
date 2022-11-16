
class Solution {
public:
    int guessNumber(int n) {
      
        int low=1,mid=1;
        int high=n;
        while(low<=high){
             mid=low+(high-low)/2;
            int ans=guess(mid);
            if(ans==0) return mid;
            else if(ans==-1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return mid;
    }
};