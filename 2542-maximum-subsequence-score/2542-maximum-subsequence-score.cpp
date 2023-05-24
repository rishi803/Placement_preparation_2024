class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        vector<pair<int,int>>v;
        
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums1[i],nums2[i]});
        }
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        long long sum=0,ans=0;
        
        for(int i=0;i<k;i++){
            sum+=v[i].first;
            minheap.push({v[i].second,v[i].first});
        }
        
        ans=(minheap.top().first*sum);
        
        for(int i=k;i<nums1.size();i++){
            sum-=minheap.top().second;
            minheap.pop();
          
            sum+=v[i].first;
            minheap.push({v[i].second,v[i].first});
            ans=max(ans,sum*minheap.top().first);
        }
        return ans;
        
    }
};