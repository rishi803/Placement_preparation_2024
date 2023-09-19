class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        
        unordered_map<int,int>visrow,viscol;
        
        reverse(queries.begin(), queries.end());
        
        int row=n, col= n;
        long long sum= 0;
        
        for(int i=0; i<queries.size(); i++){
            
            int type= queries[i][0];
            int idx= queries[i][1];
            
            if(type == 0 and visrow[idx] == 0){        
               
                int value= queries[i][2];
                
                sum+= row * value;
                visrow[idx] = 1;              // this row is changed so dont visit it again
                col--;
            }
            
            else if(type ==1 and viscol[idx] == 0){             
               
                int value= queries[i][2];
                
                sum+= col * value;
                viscol[idx]= 1;            // this col is changed so dont visit it again
                row--;
            }
        }
        
        return sum;
    }
};