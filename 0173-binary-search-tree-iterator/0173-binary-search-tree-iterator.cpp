
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        partialinorder(root);
    }
    
    void partialinorder(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* top=st.top();
        st.pop();
        partialinorder(top->right);                  // push next greater elements in stack
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */