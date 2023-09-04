
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* piche= head;
        ListNode* age= head;
        
        while(age and age->next){
            age= age->next->next;
            piche= piche->next;
            
            if(age == piche) return true;
        }
        
        return false;
        
    }
};