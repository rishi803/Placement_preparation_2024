int countSubstrings(string s) {
int n = s.length(),c=0;
if(n==0)
return 0;
int i,j;
bool dp[n][n];
memset(dp,false,sizeof(dp));
for(i=0;i<n;i++)
dp[i][i] = true;
for(i=n-2;i>=0;i--)
{
for(j=i+1;j<n;j++)
{
if(s[i] == s[j])
{
if(dp[i+1][j-1] || j-i == 1)
dp[i][j] = true;
}
}
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(dp[i][j])
c++;
}
}
return c;
}
/////////////////////// 3