//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
  
    
    bool help(vector<int>&arr,int target,int st,vector<vector<int>> &dp){
        
        if(target==0) {
          return 1;
        }
        if(st>=arr.size() or target<0) return 0;
        if(dp[target][st]!=-1) return dp[target][st];
      return dp[target][st]=help(arr,target-arr[st],st+1,dp) or help(arr,target,st+1,dp);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
    //   vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
      vector<vector<int>> dp(sum+1, vector<int>(n+1, -1));
       return help(arr,sum,0,dp);
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends