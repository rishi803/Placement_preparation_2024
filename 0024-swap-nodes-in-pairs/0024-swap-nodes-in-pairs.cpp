// https://leetcode.com/problems/swap-nodes-in-pairs/discuss/1775033/SWAPPING-NODES-(Not-just-the-values)-oror-Visual-Explanation-oror-Well-Explained-oror-C%2B%2B

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* dummy= new ListNode (0);
        ListNode* prev=dummy;
        ListNode* curr=head;
        
        while(curr and curr->next){     // (0) 1---->2----->3----->4   cur=1 ,prev=0
            prev->next=curr->next;      //  (0)--->2      1---->2---->3----->4  
            curr->next=curr->next->next; // (0)--->2      1---->3---->4    cur->next=2 , cur->next->next=3
            prev->next->next=curr;       // (0)--->2---->1--->3--->4     
            
            prev=curr;
            curr=curr->next;
        }
        return dummy->next;
    }
};