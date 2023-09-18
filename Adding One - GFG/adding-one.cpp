//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> addOne(int a[], int n) {
        // code here
       int carry= 1;
       vector<int>ans;
       
       for(int i=n-1; i>=0; i--){
           int final= a[i]+carry;
           int dig= final%10;
           carry= final/10;
           
           ans.push_back(dig);
       }
       
       if(carry) ans.push_back(carry);
       reverse(ans.begin(),ans.end());
       
       return ans;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.addOne(a, n);
        printAns(ans);
    }
    return 0;
}
// } Driver Code Ends