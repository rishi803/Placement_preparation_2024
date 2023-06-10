class Solution {
public:
    
    long cal_sum(int remainidx,long val,int totalidx){
        
        if(remainidx>val){
            int one_cnt=remainidx-val;
            long sum= (val*(val+1))/2;
            return sum+one_cnt;
        }
        else{
            long lastval=val-remainidx;
            long sum= ((val*(val+1))/2)-((lastval*(lastval+1))/2);
            return sum;
        }
    }
    
    int maxValue(int n, int index, int maxsum) {
        
        int low=1,high=maxsum,ans=1;
        
        while(low<=high){
            int mid=(low+(high-low)/2);
            
            long left=cal_sum(index,mid-1,n);
            long right=cal_sum(n-index-1,mid-1,n);
            
            long totalsum=left+right+mid;
            
            if(totalsum>maxsum){
                high=mid-1;
            }
            else{
                ans=mid;
                low=mid+1;
            }
        }
        
        return ans;
    }
};