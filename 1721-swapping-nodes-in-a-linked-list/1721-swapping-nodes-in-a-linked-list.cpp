
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr=head,*last=head,*front;
        
        while(k--){
            front=ptr;
            ptr=ptr->next;
        }
        while(ptr){
            ptr=ptr->next;
            last=last->next;
        }
        swap(front->val,last->val);
        return head;
        
    }
};