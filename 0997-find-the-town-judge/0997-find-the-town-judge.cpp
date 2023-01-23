class Solution {
public:
     int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1),outdegree(n+1); // Define an array of length n+1
        
        for(int i = 0; i < trust.size(); i++){ // loop through the 'trust' array
            outdegree[trust[i][0]]++; // if a given person trust someone then decrement the count of his index
            indegree[trust[i][1]]++; // increment the count of the index whom he trusts
            
        }
        // In last, check the 'arr' array that if there is any index having count equals to n-1
        for(int i = 1; i <=n; i++){
            if(indegree[i] == n - 1 and outdegree[i]==0)  return i; // person doesnt trust anybody but everyone else trust him. Return their index
        }
        return -1;
    }
    
};