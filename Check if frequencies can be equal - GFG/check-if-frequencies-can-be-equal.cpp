//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char,int>mp1,mp2;
	    set<pair<int,int>>st;
	    
	    for(auto i:s) mp1[i]++;
	    
	    for(auto i:mp1) mp2[i.second]+=1;
	    
	   for(auto i:mp2) st.insert({i.first,i.second});
	   
	   if(st.size()==1) return 1;
	   if(st.size()==2) {
	       int diff=0,cnt=0;
	       
	       for(auto i:st) {
	           if(i.first==1 and i.second==1) return 1;
	           if(i.second>1 and cnt==1) return 0;
	           diff=i.first-diff;
	          cnt++;
	       }
	       
	      
	       if(abs(diff)==1) return 1;
	       
	   }
	    
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends