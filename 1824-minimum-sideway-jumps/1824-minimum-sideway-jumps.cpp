// SIDEBAR--> DP & BFS

class Solution {
public:
    int minSideJumps(vector<int>& obs) {
    int n=obs.size(),step=0;
    vector<vector<int>> vis(4,vector<int>(n+1,0));
    queue<pair<int,int>> q;
    q.push({2,0});
    while(!q.empty()){
        int sz=q.size();
        for(int p=0;p<sz;p++){
            auto [x,y]=q.front();
            q.pop();
            if(x>3||x<1||y>n||y<0||vis[x][y]==1||obs[y]==x) continue;  // eliminate the invalid points 
            if(y==n-1) return step-(n-1);  // subract horizontal distance->n
            vis[x][y]=1;                    // mark visited  
            
            if(x-1>=1)
            q.push({x-1,y});              // onr step up  
            if(x-2>=1)
            q.push({x-2,y});             //two steps up
            if(x+1<=3)
            q.push({x+1,y});           //one step down
            if(x+2<=3)
            q.push({x+2,y});           //two steps down 
            if(y+1<n)
            q.push({x,y+1});         //one step right
            //(if any case is invalid it will get eliminated by if condition)
        }
        step++;
    }
    
    return -1;
}
};