class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        map<int,int>mp;
        int mx=0,sum=0;
        
        for(int i=0;i<intervals.size();i++){        // SWEEP LINE ALGO
            mp[intervals[i][0]]++;
            mp[intervals[i][1]+1]--;
        }
        
        for(auto &i:mp){
            sum+=i.second;
            mx=max(mx,sum);
        }
        
        return mx;
    }
};