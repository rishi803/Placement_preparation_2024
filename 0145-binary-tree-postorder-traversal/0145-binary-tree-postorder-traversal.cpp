
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* already_taken = nullptr;
        vector<int> ans;
        
        while (!st.empty()) {
            TreeNode* top = st.top();
            
            if ((!top->left && !top->right) || (already_taken && (top->left == already_taken || top->right == already_taken))) {
                ans.push_back(top->val);
                already_taken = top;
                st.pop();
            } else {
                if (top->right) st.push(top->right);
                if (top->left) st.push(top->left);
            }
        }
        
        return ans;
    }
};