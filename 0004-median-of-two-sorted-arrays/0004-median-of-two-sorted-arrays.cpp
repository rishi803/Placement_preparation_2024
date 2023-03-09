class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //checking whether nums2 is smaller in size if yes then calling the function as nums2,nums2 to keep the smaller one as nums1
        if(nums2.size()<nums1.size())
            return findMedianSortedArrays(nums2,nums1);
        
        //now taking sizes and low and high iterators over the nums1 array
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;
        
        //now loop for binary search
        while(low<=high)
        {
            
            int cut1 = (low+high)/2; //no. of elements picking up from nums1
            int cut2 = (n1+n2+1)/2 - cut1; //no. of elements picking up from nums2
            
            //now checking if our cut 1 is 0 then making it INT_MIN else making it and same for cut2 then making it to left1 and left2
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            //now same as above for right1 and right2
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
           
            
            //when our condition satisfies that the partition done is correct then
            if(left1<=right2 && left2<=right1)
            {
                //checking whether the sumed up array is even or odd
                if((n1+n2)%2==0)// if even
                    return (max(left1,left2)+min(right1,right2))/2.0;
                else //if odd
                    return max(left1,left2);
            }
            
            // else if our condition doesnt satisfies because our left1>right2
            else if(left1>right2)
            {
                //then we decrease the value of high 
                high = cut1-1;
            }
            else
            {
                //else if left2<right1 then we increase the vsalue of low by 1
                low = cut1+1;
            }
            
        }
        return 0.0;
        
    }
};