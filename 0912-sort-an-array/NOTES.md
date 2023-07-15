swap(nums[left],nums[right]); // swap left right and again check with pivot
}
swap(nums[low],nums[right]); // place pivot at its correct place
return right;          // this is pivot_idx which is correct pos of pivot element
}
void quicksort(vector<int>&nums,int low,int end){
if(low>=end) return;
int pivot_idx = partition(nums,low,end);
quicksort(nums,low,pivot_idx-1);
quicksort(nums,pivot_idx+1,end);
}
vector<int> sortArray(vector<int>& nums) {
quicksort(nums,0,nums.size()-1);
return nums;
}
};
```
​
​