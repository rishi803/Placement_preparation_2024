class Solution {
public:
    // Finds no. of nodes in list
    int nodeCount(ListNode* head) {
        int cnt=1;
        while(head and head->next) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    
    // TC: O(N)
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // N/k gives max equal no. of nodes per block. In order to keep the
        // max diff 1, we add 1 from each of the remaining N % k elements
        // to the groups from start
        const int N = nodeCount(root);
        
        int elements_per_group = N / k;
        int extra_nodes = N % k;
        
        vector<ListNode*> result(k);
        if(!root) return result;
        ListNode *curr = root;
        
        for(int i = 0; i < k; i++) {
            int remaining = elements_per_group;
            // if any extra nodes needs to added
            if(extra_nodes > 0) {
                remaining += 1;
                --extra_nodes;
            }

            result[i] = curr;      // you can also insert curr/root here it will break afterwards by prev
            ListNode *prev = nullptr;
          
            while(remaining--) {    // traverse the no. of nodes that will be assigned
                prev = curr;
                curr = curr->next;
            }
            // end the list
            if(prev){
                // result[i]=root;              // root to prev is separated to insert
                prev->next = nullptr;
                // root=curr;                  // update root to curr list started after separator
            }
                
        }    
        
        return result;
    }
};