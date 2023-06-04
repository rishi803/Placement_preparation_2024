class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
         long sum = 0;
         int row = n, col = n;
        
         unordered_set<int>Rowvis;
         unordered_set<int>Colvis;

    for (int i = queries.size() - 1; i >= 0; i--) {
        
        int type=queries[i][0];
        int idx=queries[i][1];
        int value=queries[i][2];
        
        if (type==0) {
            if (Rowvis.find(idx)!=Colvis.end()) {            // because this index is already calculated
                continue;
            } 
            else {                     
               
                sum += col* value;
                Rowvis.insert(idx);
                row --;
              
            }
        } else {
            if (Colvis.find(idx)!=Colvis.end()) {        // because this index is already calculated
                continue;
            }
            else {
               
                sum += row * value;
                Colvis.insert(idx);
                col --;
            }
        }
    }

    return sum;

    }
};