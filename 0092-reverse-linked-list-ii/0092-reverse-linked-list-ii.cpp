
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
          ListNode* l= head;
          ListNode* r= head;
        ListNode* prev= nullptr;
          
          left--;
          right--;
        
        while(left--){
            prev= l;
            l= l->next;
        }
        
        while(right--){
            r= r->next;
        }
        
        if(r==head) return head;
        bool flag= 0;
        
        if(prev != nullptr){
            flag=1;
            prev->next= r;
        }
        
        
        ListNode* piche= r->next;
        r->next= nullptr;
        
        ListNode* curr= l;

        
       while(curr){
           ListNode* temp= curr->next;
           curr->next= piche;
           piche=curr;
           curr=temp;
       }
        
        if(flag==0) return piche;
        return head;
    }
};