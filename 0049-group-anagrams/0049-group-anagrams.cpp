class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {{}};
        vector<pair<string,string>>ve;
        vector<vector<string>>res;
        vector<string>temp;
        for(int i=0;i<strs.size();i++){
          string tem=strs[i];
            sort(tem.begin(),tem.end());
             ve.push_back({tem,strs[i]});
        }
        sort(ve.begin(),ve.end());
        // for(auto it:ve){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(int i=0;i<strs.size();i++){
          
            temp.emplace_back(ve[i].second);
            if( i<strs.size()-1 and ve[i].first!=ve[i+1].first){
                res.emplace_back(temp);
                temp.clear();
            }
        }
        res.emplace_back(temp);
        return res;
    }
};