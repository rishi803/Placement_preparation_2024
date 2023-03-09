/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         
        if(!head) return false;
        
        
        ListNode* piche=head;
        ListNode* age=head;
        
        while(age and age->next){
            
            age=age->next->next;    // move 2 step
            piche=piche->next;      // move 1 step
            
           if(age==piche){
               
               return true;  // ya to "piche" bhi return kr skte ho kunki ab dono same node h
           }
            
            
        }
        
       
        
        return false;
    }
};