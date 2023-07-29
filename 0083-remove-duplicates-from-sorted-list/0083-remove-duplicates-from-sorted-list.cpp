
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head,*prev;
        
        while(curr and curr->next){
            prev=curr;
            curr=curr->next;
            if(prev->val==curr->val){
                // cout<<"h";
                while(curr){
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp; // Free the memory for the duplicate node
                    if(curr and curr->val!=prev->val) break;
                }
                prev->next=curr;
            }
        }
        return head;
    }
};