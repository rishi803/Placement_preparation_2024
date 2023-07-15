
class Solution {
public:
    
    TreeNode* help(vector<int>&nums,int st,int end){
        
        if(st>end) return nullptr;
        
        int mid=st+(end-st)/2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        root->left= help(nums,st,mid-1);
        root->right= help(nums,mid+1,end);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums,0,nums.size()-1);
    }
};