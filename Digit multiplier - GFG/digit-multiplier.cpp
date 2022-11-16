//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string getSmallest(long long n) {
          if(n>=0 and n<=9) return to_string(n);
   stack<int>ans;
   for(int i=9;i>=2;i--){
       if(n==1) break;
       while(n%i==0){
           ans.push(i);
           n=n/i;
       }
   }
   if(n!=1) return "-1";
     long long int k = 0;
    while (!ans.empty())
    {
        k = k*10 + ans.top();
        ans.pop();
    }
     
    // required smallest number
    
   return to_string(k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.getSmallest(N) << endl;
    }
    return 0;
}
// } Driver Code Ends