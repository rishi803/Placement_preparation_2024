class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
       vector<int>mp(n+2,0);
        int seats=0;
        
        for(auto &i:bookings){
            
            int start= i[0];
            int end= i[1];
            
            mp[start]+=i[2];
            mp[end+1]-=i[2];
        }
        vector<int>ans;
        
        for(int i=1;i<=n;i++){
            seats+=mp[i];
            ans.push_back(seats);
        }
        return ans;
    }
};