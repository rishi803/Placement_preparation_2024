class Solution {
public:
    int minJumps(vector<int>& arr) {
         int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++)
            indicesOfValue[arr[i]].push_back(i);
        vector<bool> visited(n); visited[0] = true;
        queue<int> q; q.push(0);
        int step = 0;
        while (!q.empty()) {
            int sz=q.size();
            while(sz--) {
                int i = q.front(); q.pop();
                if (i == n - 1) return step; // Reached to last index
                // indicesOfValue[arr[i]].push_back(i-1);                   // it is giving error 
                // indicesOfValue[arr[i]].push_back(i+1);
                // for(auto &it:indicesOfValue){
                //     for(auto &itr:it.second){
                //         if(itr>=0 and itr<n and visited[itr]==0){
                //             visited[itr]=1;
                //             q.push(itr);
                //         }
                //     }
                // }
                 vector<int>&ind=indicesOfValue[arr[i]];
                ind.push_back(i-1);
                ind.push_back(i+1);
               
                    for(auto &itr:ind){
                        if(itr>=0 and itr<n and visited[itr]==0){
                            visited[itr]=1;
                            q.push(itr);
                        }
                indicesOfValue[arr[i]].clear(); // avoid later lookup indicesOfValue arr[i]
            }
            }
            step++;
        }
        return step;
    }
};