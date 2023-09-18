class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multimap<int,int>ans;
        vector<int>res;
        for(int i=0;i<mat.size();i++){
          int freq=count(mat[i].begin(),mat[i].end(),1);
         ans.insert(pair<int, int>(freq,i));
            cout<<i<<" ";
        }
        // for(auto it:ans) cout<<"h "<<it.first<<" "<<it.second;
        for(auto it:ans){
            // cout<<it.second<<" ";
            if(k>0)
            res.push_back(it.second);
            k--;
        }
      return res;
    }
};