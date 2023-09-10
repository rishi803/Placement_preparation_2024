//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  public:
  
    void help(vector<vector<int>>&grid, int i, int j, int basei, int basej, vector<pair<int,int>>&v){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0) return;
        
        grid[i][j]= 0;
        
        v.push_back({(basei-i), (basej-j)});
        
        
        help(grid, i+1,j,basei,basej,v);
        help(grid,i,j+1,basei,basej,v);
        help(grid,i-1,j,basei,basej,v);
        help(grid,i,j-1,basei,basej,v);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        set<vector<pair<int,int>>>st;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                     
                     vector<pair<int,int>>v;
                     help(grid, i, j, i, j, v);
                     grid[i][j]= 0;
                    //  cout<<i<<" "<<j<<" "<<islandsum<<endl;
                     
                     st.insert(v);
                }
            }
        }
        
        return st.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends