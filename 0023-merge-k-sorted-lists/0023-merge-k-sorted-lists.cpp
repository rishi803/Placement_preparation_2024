
class Solution {
public:
    
    
    ListNode* mergesort(ListNode* first,ListNode* second){
        if(!first and !second) return nullptr;
        if(first and !second) return first;
        if(!first and second) return second;
        
        if(first->val<=second->val){
            first->next= mergesort(first->next,second);
            return first;
        }
        else{
            second->next= mergesort(first,second->next);
            return second;
        }
    }
    
   ListNode*  partition(vector<ListNode*>&lists,int st,int end){
        
       
        if(st==end) return lists[st]?lists[st]:nullptr;
       
       int mid= st + (end-st)/2;
       ListNode* first=  partition(lists,st,mid);
       ListNode* second=  partition(lists,mid+1,end);
       
       return mergesort(first,second);
     
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int sz=lists.size();
        if(sz==0) return nullptr;
        
        return partition(lists,0,sz-1);
        
        
        
    }
};