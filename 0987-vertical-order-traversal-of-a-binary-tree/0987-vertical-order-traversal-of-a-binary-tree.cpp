
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        
        //nodes -> to store vertical, level and nodes at that (vertical, level) point
        map<int, map<int, multiset<int>>> nodes;        // (vertical,(level,node_at_that_level));
        
        //todo -> to store node with respect to it's vertical and level
        queue<pair<TreeNode*, pair<int, int>>> todo;   // (node,(vertical,level));
        
        todo.push({root, {0,0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first;  //vertical
            int y = p.second.second; //level
            
            nodes[x][y].insert(node->val);
            
            if(node->left)
                todo.push({node->left, {x - 1, y + 1}});
            if(node->right)
                todo.push({node->right, {x + 1, y + 1}});
        }
        
        for(auto p : nodes){
            vector<int> col;
            for(auto i : p.second){
                for(auto it:i.second) col.push_back(it);
                // col.insert(col.end(), i.second.begin(), i.second.end());
            }
            // cout<<endl;
            
            ans.push_back(col);
        }
        
        return ans;
    }
    
};