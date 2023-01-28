class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        unordered_map<int,int>mp;
        int head=0,tail=0,mnAns=INT_MAX;
        
        for(head=0;head<cards.size();head++){
            mp[cards[head]]++;
            
            while(mp[cards[head]]>1){
                mnAns=min(mnAns,head-tail+1);
                mp[cards[tail]]--;
                tail++;
            }
        }
        return mnAns==INT_MAX?-1:mnAns;
    }
};