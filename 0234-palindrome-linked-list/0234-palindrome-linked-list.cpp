
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      ListNode* slow=head;
      ListNode* fast=head;
      int half=1;
        
      while(fast and fast->next){
          slow=slow->next;
          fast=fast->next->next;
          half++;
      }
        
        if(fast) slow=slow->next,half--;
        
        fast=head;
        ListNode*prev=nullptr,*nextnode;
  
        while(slow){
            nextnode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextnode;
        }
        
        while(half-- and prev and fast){
            // cout<<prev->val<<" "<<fast->val<<endl;
            if(prev->val!=fast->val) return false;
            prev=prev->next;
            fast=fast->next;
        }
        return true;
    }
};