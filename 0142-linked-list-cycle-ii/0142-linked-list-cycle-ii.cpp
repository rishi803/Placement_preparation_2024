
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head) return nullptr;
        
        
        ListNode* piche=head;
        ListNode* age=head;
        
        while(age and age->next){
            
            age=age->next->next;
            piche=piche->next;
            
           if(age==piche){
               piche=head;
               
               while(age!=piche){
                   age=age->next;
                   piche=piche->next;
               }
               return age;  // ya to "piche" bhi return kr skte ho kunki ab dono same node h
           }
            
            
        }
        
       
        
        return nullptr;
    }
};