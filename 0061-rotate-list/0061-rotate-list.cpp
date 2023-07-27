
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode* temp=head;
        int len=1;
        
        while(temp and temp->next){
            temp=temp->next;
            len++;
        }
     
        ListNode* prev=head;
        k=k%len;
        
        if(k==0) return head;
        
        else
        {
            k=len-k-1;
            while(k--){
                prev=prev->next;
            }

            temp->next=head;
            head=prev->next;
            prev->next=nullptr;
            
        }
        return head;
    }
};