class Solution {
public:
    
    void merge(vector<int>&nums,int low,int mid,int high){
        
        vector<int>left(mid-low+1),right(high-mid);
        
        for(int i=0;i<left.size();i++){
            left[i]=nums[low+i];
        }
        
        for(int i=0;i<right.size();i++){
            right[i]=nums[mid+1+i];
        }
        
        int i=0,j=0,k=low;
        
        while(i<left.size() and j<right.size()){
            
            if(left[i]<right[j]){
                nums[k]=left[i];
                i++;
            }
            else{
                nums[k]=right[j];
                j++;
            }
            
            k++;
        }
        
        while(i<left.size()){
            nums[k]=left[i];
            i++;
            k++;
        }
        
        while(j<right.size()){
            nums[k]=right[j];
            j++;
            k++;
        }
    }
    
    void divide(vector<int>&nums,int low,int high){
       
        if(low<high){
            int mid=low+(high-low)/2;
            
            divide(nums,low,mid);
            divide(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        int sz=nums.size();
        int low=0,high=sz-1;
        
        divide(nums,low,high);
        return nums;
    }
};