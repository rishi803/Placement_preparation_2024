ans=mid_sum;
high=mid_sum-1;
}
else{
low=mid_sum+1;
}
}
return low;
}
};
```
​
**2. RECURSION DP**
​
```
class Solution {
public:
int dp[1001][51];
int solve(vector<int>& nums,int idx,int k)
{
if(idx==nums.size() && k==0)
{
return 0;
}
if(idx==nums.size() || k==0)
return INT_MAX;
if(dp[idx][k]!=-1)
return dp[idx][k];
int res=INT_MAX,cnt=0;
for(int i=idx;i<nums.size();i++)
{
cnt+=nums[i];
int p=solve(nums,i+1,k-1);
int ans=max(cnt,p);
res=min(res,ans);
}
return dp[idx][k]=res;
}
int splitArray(vector<int>& nums, int m)
{
memset(dp,-1,sizeof(dp));
return solve(nums,0,m);
}
};
​
```