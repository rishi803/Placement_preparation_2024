class Solution {
public:
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
priority_queue<int,vector<int>,greater<int>>minheap;
vector<pair<int,int>>v;
for(int i=0;i<nums1.size();i++){
v.push_back({nums2[i],nums1[i]});
}
sort(v.begin(),v.end(),greater<pair<int,int>>());
long long sum=0,ans=0;
for(int i=0;i<k;i++){
sum+=v[i].second;
minheap.push(v[i].second);
}
ans=(v[k-1].first*sum);
for(int i=k;i<nums1.size();i++){
sum-=minheap.top();
minheap.pop();
sum+=v[i].second;
minheap.push(v[i].second);
ans=max(ans,sum*v[i].first);
}
return ans;
}
};