
class Solution {
public:
    int sz=0;
    
    ListNode* reverse(ListNode* head){
       ListNode*temp=head,*naya=nullptr;
        
        while(head){
            temp= head->next;
            head->next=naya;
            naya=head;
            head=temp;
            sz++;
        }
        
        return naya;
    }
    
    int pairSum(ListNode* head) {
        
        
        ListNode* fir=head;
        vector<int>v;
        while(fir){
            v.push_back(fir->val);
            fir=fir->next;
        }
        ListNode* sec=reverse(head);
        int ans=0;
        
        sz=sz/2;
        int i=0;
        while(sz-- and sec){
            int sum=v[i]+sec->val;
            sec=sec->next;
            ans=max(ans,sum);
            i++;
        }
        
        return ans;
    }
};