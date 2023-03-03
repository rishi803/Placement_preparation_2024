// Time: O(M*N log M*N)
// Space: O(M*N)
    
// We need to store the efforts based on the row and column we are currently at. So by doing row*100 + col, we are essentially storing both the row number and column number in a single int. Else, we would have to take pair<int, pair<int, int>> for {effort, {row, col}}

//  vector<vector<int>> dirs = {
//                 {-1,0},
//         {0,-1},         {0,1},
//                 {1, 0}
//     };


class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    int dirs[5] = {-1, 0, 1, 0, -1};

    std::vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
    unordered_map<int,int>vis;   // if a coordinate is already visited don't visit it again

    pq.emplace(0, 0); // First item is effort, second is row * 100 + col
    while (!pq.empty()) {
      int effort = pq.top().first;
      int x = pq.top().second / 100, y = pq.top().second % 100;
      pq.pop();

      if (effort >= efforts[x][y]) continue;     // lever of problem
      efforts[x][y] = effort;
       vis[x*100+y]++;
      for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i], ny = y + dirs[i + 1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis.count(nx*100+ny)) continue;
          
        int n_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
          // cout<<n_effort<<" nx= "<<nx<<" ny= "<<ny<<endl;
        pq.emplace(n_effort, nx * 100 + ny);
      }
    }
    return efforts[m-1][n-1];
  }
};