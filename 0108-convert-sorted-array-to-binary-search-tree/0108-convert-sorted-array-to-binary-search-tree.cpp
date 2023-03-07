
class Solution {
public:
    TreeNode* helper(vector<int>&arr,int s,int e){
     
        if(s<=e){
            int mid=s+(e-s)/2;
            
            TreeNode* node=new TreeNode(arr[mid]);
            node->left=helper(arr,s,mid-1);
            node->right=helper(arr,mid+1,e);
            
            return node;
        }
        else return nullptr;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(nums,0,n-1);
    }
};