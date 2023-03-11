// find mid node each time (by Fast and Slow pointer)
// MOST IMP:  separate list in two parts each time by (prev of mid->next= null or 0); (mid is slow pointer)

class Solution {
public:
     TreeNode *sortedListToBST(ListNode *head) {
            if(!head) return NULL;
            if(!head->next) return new TreeNode(head->val);
            
            // fast/slow pointer to find the midpoint
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* pre = head;
         
            while(fast && fast->next) {
                pre = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            pre->next = nullptr; // break two halves 
            
            // slow is the midpoint, use as root
            TreeNode* root = new TreeNode(slow->val);
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(slow->next);
            
            return root;
        }
};