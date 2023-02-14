/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> result;
    
    void help(Node* root){
        if(!root) return ;
        
        for(int i=0;i<root->children.size();i++){
            result.push_back(root->children[i]->val);
            help(root->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        
//         if (root == nullptr) {
//             return result;
//         }
        
//         stack<Node*> stk;
//         stk.push(root);
//         while (!stk.empty()) {
//             Node* cur = stk.top();
//             stk.pop();
//             result.push_back(cur -> val);
//             for (int i = cur -> children.size() - 1; i >= 0; i--) {
//                 if (cur -> children[i] != nullptr) {
//                     stk.push(cur -> children[i]);
//                 }
//             }
//         }
        if(!root) return {};
        result.push_back(root->val);
        help(root);
        return result;
    }
};