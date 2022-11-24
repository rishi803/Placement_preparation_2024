class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>temp;
        vector<int>ans;
        for(int i=1;i<=n;i++){
            string str=to_string(i);
            temp.push_back(str);
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            int res=stoi(temp[i]);
            ans.push_back(res);
        }
        return ans;
    }
    
};