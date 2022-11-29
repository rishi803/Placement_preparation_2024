class Solution {
public:
   vector<int> rearrangeBarcodes(vector<int>& b) {
        unordered_map<int,int> m;
        // freq 
        for(auto i:b) m[i]++;
        priority_queue<pair<int,int>> pq;
        // storing freq and its element in pq
        for(auto i:m) pq.push({i.second,i.first});
        vector<int> v(b.size(),0);
        // first put max freq element at even places then remaining on odd places 
        int i=0;
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            while(p.first--){
                if(i>=b.size()) i=1;
                v[i]=p.second;
                i+=2;
            }
        }
        return v;
    }
    
};