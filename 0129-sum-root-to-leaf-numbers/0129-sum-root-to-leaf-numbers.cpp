/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum=0;
    void help(TreeNode* root,int temp){
        if(!root) return;
        temp=temp*10+root->val;
        if(!root->left and !root->right){
            // cout<<temp<<endl;
            sum+=temp;
            return;
        }
        
        help(root->left,temp);
        help(root->right,temp);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int temp=0;
        help(root,temp);
        
        return sum;
    }
};