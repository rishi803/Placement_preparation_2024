// https://leetcode.com/problems/swap-nodes-in-pairs/discuss/1775033/SWAPPING-NODES-(Not-just-the-values)-oror-Visual-Explanation-oror-Well-Explained-oror-C%2B%2B

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* dummy= new ListNode (0);
        ListNode* prev=dummy;
        ListNode* curr=head;
        
        while(curr and curr->next){
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev->next->next=curr;
            
            prev=curr;
            curr=curr->next;
        }
        return dummy->next;
    }
};