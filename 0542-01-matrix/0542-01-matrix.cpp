class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r)
        { for (int c = 0; c < n; ++c)
                if (mat[r][c] == 0) q.emplace(r,c);
                else mat[r][c] = -100; }// Marked as not processed yet!

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + DIR[i], nc = c + DIR[i+1];
                if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -100) continue;
                mat[nr][nc] = mat[r][c]+1;  //if we found -1 means it is 1 so to updatae it by adding +1 in its root grid after storing its ans so that it distance helps in finding distance for its surrounding -1 add+1
                q.emplace(nr, nc);
            }
        }
        return mat;
    }
};