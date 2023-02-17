class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int,int>priyanshu;
        
        for(int i=0;i<arr.size();i++){
            priyanshu[arr[i]]++;
        }
        
        unordered_set<int>st;
        for(auto &[fir,sec]:priyanshu){
            st.insert(sec);
        }
        
        if(st.size()!=priyanshu.size()) return false;
        return true;
    }
};