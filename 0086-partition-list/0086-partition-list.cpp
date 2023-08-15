
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1= new ListNode(0);
        ListNode* l2= new ListNode(0);
        
        ListNode* temp1=l1, *temp2= l2;
        
        while(head){
            if(head->val < x){
                l1->next= head;
                l1=l1->next;
            }
            
            else{
                l2->next= head;
                l2= l2->next;
            }
            head= head->next;
        }
        
        l1->next= temp2->next;
        l2->next= nullptr;
        return temp1->next;
        
        // l1->next= temp2->next;
        // l1= temp1->next;
        // return l1;
    }
};