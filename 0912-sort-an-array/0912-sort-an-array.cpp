class Solution {
public:
    void merge(vector<int>&nums,int st,int mid,int end){
        int leftsz=mid-st+1;
        int rightsz=end-mid;
        
        vector<int>left(leftsz),right(rightsz);
        
        for(int i=0;i<leftsz;i++){
            left[i]=nums[st+i];
        }
        for(int i=0;i<rightsz;i++){
            right[i]=nums[mid+1+i];
        }
        
        int i=0,j=0,k=st;
        
        while(i<leftsz and j<rightsz){
            if(left[i]<=right[j]){
                nums[k++]=left[i];
                i++;
            }
            else {
                nums[k++]=right[j];
                j++;
            }
        }
        while(i<leftsz){
            nums[k++]=left[i++];
        }
        while(j<rightsz){
            nums[k++]=right[j++];
        }
    }
    
    void mergesort(vector<int>&nums,int st,int end){
        
        if(st>=end) return;
        int mid=st+(end-st)/2;
        mergesort(nums,st,mid);
        mergesort(nums,mid+1,end);
        merge(nums,st,mid,end);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};