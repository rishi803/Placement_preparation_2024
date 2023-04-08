/*
public:
    int val;
    vector<Node*> neighbors;
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        
        if(!node) return nullptr;
        
         unordered_map<Node*,Node*>mp;
         Node *reference=new Node(node->val,{});
         mp[node]=reference;
        
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            auto curnode=q.front();
            q.pop();
            
            for(auto child:curnode->neighbors){
                if(mp.find(child)==mp.end()){
                    Node *reference=new Node (child->val,{});
                    mp[child]=reference;
                    q.push(child);
                }
                
                mp[curnode]->neighbors.push_back(mp[child]);
            }
        }
        
        return reference;       // or return mp[node]
    }
};