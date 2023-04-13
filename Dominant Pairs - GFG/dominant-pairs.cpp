//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        
        vector<int>temp1,temp2;
        for(int i=0;i<n/2;i++){
            temp1.push_back(arr[i]);
        }
        for(int i=n/2;i<n;i++){
            temp2.push_back(arr[i]);
        }
        
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        int ans=0;
        for(int i=0;i<temp2.size();i++){
           int idx=lower_bound(temp1.begin(),temp1.end(),(5*temp2[i]))-temp1.begin();
            ans+=(temp1.size()-idx);
        }
        
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends