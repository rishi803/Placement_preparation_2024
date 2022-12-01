class Solution {
public:
    bool isPalin(string s,int st,int end){
        while(st<=end){
           if(s[st++]!=s[end--]) return false;
        }
        return true;
    }
    void func(int index,string s,vector<string>&path,vector<vector<string>>&ans){
        
        //base case
        
        if(index==s.size()){
            ans.push_back(path);
            return;
        }
        
        //calculation
        
        for(int i=index;i<s.size();i++){
            if(isPalin(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                func(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        func(0,s,path,ans);
        return ans;
    }
}; 