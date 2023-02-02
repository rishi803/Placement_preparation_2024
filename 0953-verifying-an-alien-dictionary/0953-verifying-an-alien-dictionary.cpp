class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        int i=0;
        for(auto &it:order){
            mp[it]='a'+i;
            i++;
        }
        string prev;
        for(int i=0;i<words.size();i++){
            string temp;
            for(int j=0;j<words[i].size();j++){
                 temp+=mp[words[i][j]];
            }
            // cout<<temp<<endl;
            if(i!=0 and temp<prev)  return false;
            prev=temp;
        }
        return true;
    }
};