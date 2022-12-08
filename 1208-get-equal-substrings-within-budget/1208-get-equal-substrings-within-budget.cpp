class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int head=0,tail=0,cost=0,len=0;
        for(head=0;head<s.size();head++){
            cost=cost+abs(s[head]-t[head]);
            while(cost>maxCost){
                cost=cost-abs(s[tail]-t[tail]);
                len=max(len,head-tail);
                tail++;
            }
            len=max(len,head-tail);
        }
        return max(len,head-tail);
    }
};