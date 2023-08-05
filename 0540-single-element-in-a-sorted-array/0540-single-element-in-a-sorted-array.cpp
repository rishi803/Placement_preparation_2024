// index:   0 1 2 3 4 5 6 7 8
// vector: [1,1,2,3,3,4,4,8,8]
//                   \U0001f446 (Target element is 2 since it appears once)
// In this example, before 2 every first instance of element occurs at even index and second instance at odd index (see element 1) and after 2 every first instance of element occurs at odd index and second instance at even index (see element 3, 4 and 8).

// So from the above observation we will apply binary search on our array, and if we are on the PART - B side of array, we go to left, otherwise we go right.

// mid^1 explanation:
// If mid is odd then (mid^1) will always be the even number before mid
// If mid is even then (mid^1) will always be the odd number after mid

// And hence I am able to check whether mid is in left half or right half as:

// Suppose mid is odd: then mid^1 will give even number before it, 
// then if nums[mid] == nums[mid^1] 
// then 1st instance at even (mid^1) and 2nd instance at odd (mid), 
// hence we are on left side otherwise we are on right side.

// Suppose mid is even: then mid^1 will give odd number after it, 
// then if nums[mid] == nums[mid^1]
// then 1st instance at even (mid) and 2nd instance at odd (mid^1), 
// hence we are on left side otherwise we are on right side

class Solution {
public:
   // Binary Search Approach
int singleNonDuplicate(vector<int>& nums) {
    int start = 0;
    int end = nums.size()-1;
    
    
    while(start<=end and nums.size()>1){     
        int mid = start + (end - start)/2;
        
        if(mid&1 and nums[mid] == nums[mid-1] or mid%2==0 and nums[mid] == nums[mid+1])
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    return nums[start];
}
};