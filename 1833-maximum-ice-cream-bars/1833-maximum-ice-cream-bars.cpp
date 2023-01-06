class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs),end(costs));
        int cnt=0;
        for(int i=0;i<costs.size();i++){
            coins-=costs[i];
            if(coins>=0) cnt++;
            else break;
        }
        return cnt;
    }
};