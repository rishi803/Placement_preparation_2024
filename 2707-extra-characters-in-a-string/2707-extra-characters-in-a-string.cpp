class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
    unordered_map<string,int> d;

    for (const string& word : dictionary) {
        d[word]=1;
    }

    int n = s.length();
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        
        for (int j = i; j >= 1; j--) {
            string sub = s.substr(j - 1, i - j+1);
             // cout<<dp[i]<<" i= "<<i<<" j= "<<j<<" "<<sub<<" ";
            if (d[sub] > 0) {
                // cout<<dp[j-1]<<" dp[i]= "<< min(dp[i], dp[j - 1])<<endl;;
                dp[i] = min(dp[i], dp[j - 1]);
                
            }
            // cout<<endl;
        }
        // cout<<endl<<endl;
    }

    return dp[n];
    }
};