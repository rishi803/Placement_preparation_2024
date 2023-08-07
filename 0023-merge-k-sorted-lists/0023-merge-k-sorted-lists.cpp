
class Solution {
public:
    
    ListNode* sort(ListNode* l1, ListNode* l2){
        
        if(!l1 and !l2) return nullptr;
        if(!l1 and l2) return l2;
        if(!l2 and l1) return l1;
        
        if(l1->val <= l2->val){
            l1->next= sort(l1->next, l2);
            return l1;
        }
        else{
            l2->next= sort(l1, l2->next);
            return l2;
        }
    }
    
    ListNode* help(vector<ListNode*>& lists, int st, int end){
        if(st > end) return nullptr;
        if(st == end) return lists[st];
        
        int mid= st + (end-st)/2;
        
        ListNode* l1= help(lists, st, mid);
        ListNode* l2= help(lists, mid+1, end);
        
        return sort(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        return help(lists, 0, lists.size()-1);
    }
};