class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<pair<string,string>,double> hm;
        int n = equations.size();
        vector<double> ans(queries.size(),-1);
        for(int i = 0; i < n; i++){
            hm[{equations[i][0], equations[i][1]}] = values[i];
            hm[{equations[i][1], equations[i][0]}] = double(1/values[i]);
            hm[{equations[i][0], equations[i][0]}] = 1;
            hm[{equations[i][1], equations[i][1]}] = 1;
        }

        int temp = 0;
        while(temp!=hm.size()){
            temp = hm.size();
            for(auto it = hm.begin(); it!=hm.end(); it++){
                for(auto it2 = hm.begin(); it2!=hm.end(); it2++){
                    if(it == it2) continue;
                    if(it->first.second == it2->first.first && it->first.first != it2->first.second){
                        hm[{it->first.first,it2->first.second}] = it->second * it2->second;
                        hm[{it2->first.second,it->first.first}] = 1/(it->second * it2->second);
                    }
                }
            }
        }

        for(int i = 0; i < ans.size(); i++)
            if(hm.find({queries[i][0],queries[i][1]})!=hm.end())
                ans[i] = hm[{queries[i][0],queries[i][1]}];

        return ans;
    }
};