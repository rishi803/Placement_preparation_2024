class Solution {
public:
    string reorganizeString(string s) {
        
        string ans;
        priority_queue<pair<int,char>>mxheap;
        unordered_map<char,int>hash;
        
        for(auto i: s){
            hash[i]+=1;
        }
        
        for(auto [ch, freq] : hash) {
            mxheap.push({freq, ch});
            // cout<<ch<<" "<<freq<<endl;
        }
        
        while(mxheap.size() > 1){
            
            auto largest= mxheap.top();
            mxheap.pop();
            auto seclargest= mxheap.top();
            mxheap.pop();
            
            ans+=largest.second;
            ans+=seclargest.second;
            
            largest.first-=1;
            seclargest.first-=1;
            
            // cout<<largest.first<<" "<<seclargest.first<<endl;
            
            if(largest.first > 0) mxheap.push(largest);
            if(seclargest.first > 0) mxheap.push(seclargest);
            
        }
        
        if(!mxheap.empty()){
            if(mxheap.top().first > 1) return "";
            else ans+=mxheap.top().second;
        }
        
        return ans;
    }
};