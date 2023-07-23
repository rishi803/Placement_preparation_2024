
class Solution {
public:
    
    
    
    ListNode* findmiddle(ListNode* head){
        ListNode* temp=head;
        ListNode* slow=head,*fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* mid){
        ListNode* curr=mid;
        ListNode* prev=nullptr;
        
        while(curr){
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(!head or !head->next) return;
        // find mid
        auto mid=findmiddle(head);
        auto reversemid=reverse(mid);
        ListNode* start=head->next;
        // while(reversemid){
        //     cout<<reversemid->val<<" ";
        //    reversemid=reversemid->next;
        // }
        
        for(int i=0;start!=reversemid;i++){
           head->next=reversemid;
            reversemid=reversemid->next;
           head=head->next;
           head->next=start;
            if(start and start->next)
            start=start->next;
            head=head->next;
        }
        
    }
};