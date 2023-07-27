
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode* temp=head;
        int len=1;
        
        while(temp and temp->next){      // find complete ll length
            temp=temp->next;             // send this temp to last node
            len++;
        }
     
        ListNode* prev=head;      
        
        k=k%len;     // rotation can only done upto its length (len=5, rotation_possible=1,2,3,4)
        
        if(k==0) return head;
        
        else
        {
            k=len-k-1;          // where "k" rotate start from start
            while(k--){         // send this "prev" just before to there "k" rotate start from node
                prev=prev->next;
            }

            temp->next=head;     // now point last node to head of the ll
            head=prev->next;     // now head will be next node of prev where rotation starts
            prev->next=nullptr;  // prev ka next will now become last node pointing null value
            
        }
        return head;
    }
};