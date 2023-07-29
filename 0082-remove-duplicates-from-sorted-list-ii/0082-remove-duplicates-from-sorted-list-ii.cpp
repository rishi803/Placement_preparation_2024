
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* prev= dummy;
        ListNode* curr= head;
        
        
        while(curr and curr->next){
            bool flag=false;
            while(curr and curr->next and curr->val==curr->next->val){
                ListNode* temp=curr;
                curr=curr->next;
                delete(temp);      // to avoid memory leak delete curr
                flag=true;
            }
            if(flag){
                prev->next=curr->next;
            }
            else{
                prev=curr;
            }
            curr=curr->next;
            
        }
        return dummy->next;
    }
};