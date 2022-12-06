
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next or !head->next->next){
            return head;
        }
        ListNode* o=head;
        ListNode* e=head->next;
        ListNode* elink=head->next;
        
        while(o->next and e->next){
            o->next=e->next;
            e->next=o->next->next;
            o=o->next;
            e=e->next;
        }
        o->next=elink;
        return head;
    }
};