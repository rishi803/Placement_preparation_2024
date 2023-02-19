**Using queue (BFS)**
```
​
class Solution {
public:
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
vector<vector<int>>ans;
if(!root) return ans;
queue<TreeNode*>q;
int cnt=0;
q.push(root);
while(!q.empty()){
int sz=q.size();
vector<int>temp;
while(sz--){
auto f=q.front();
q.pop();
temp.push_back(f->val);
if(f->left){
q.push(f->left);
}
if(f->right){
q.push(f->right);
}
}
if(cnt&1) reverse(temp.begin(),temp.end());
ans.push_back(temp);
cnt++;
}
return ans;
}
};
```
​
**2. Using Recursion ( DFS )**
​