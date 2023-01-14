class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]!=x) return find(parent[x]);
        else return x;
    }
    
    void combine(int x,int y){
        int parentx=find(x);
        int parenty=find(y);
        
        if(parentx==parenty) return;
        if(parentx<parenty) parent[parenty]=parentx;
        else parent[parentx]=y;
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        iota(begin(parent),end(parent),0);
        for(int i=0;i<s1.size();i++){
            combine(s1[i]-'a',s2[i]-'a');
        }
        
        string ans;
        for(int i=0;i<baseStr.size();i++){
            int mn=find(parent[baseStr[i]-'a']);
            ans+=('a'+mn);
        }
        return ans;
    }
};