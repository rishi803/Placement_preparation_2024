class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int>mp1,mp2;
        
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]++;
        
        }
        
        for(int i=0;i<nums2.size();i++){
           
            mp2[nums2[i]]++;
        }
        
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        
        nums1.erase(unique(begin(nums1),end(nums1)),end(nums1));
        nums2.erase(unique(begin(nums2),end(nums2)),end(nums2));
        
        vector<int>temp,temp2;
        
        for(int i=0;i<nums1.size();i++){
            if(mp2[nums1[i]]==0) temp.push_back(nums1[i]);
           
        }
        for(int i=0;i<nums2.size();i++){
             if(mp1[nums2[i]]==0) temp2.push_back(nums2[i]);
        }
        return {temp,temp2};
    }
};