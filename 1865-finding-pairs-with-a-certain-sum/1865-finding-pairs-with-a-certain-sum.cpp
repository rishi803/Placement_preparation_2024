class FindSumPairs {
public:
    vector<int>fir,sec;
    unordered_map<int,int>mp;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        fir=nums1;
        sec=nums2;
        for(auto i:nums2){
            mp[i]++;
        }
    }
    
    void add(int index, int val) {
        
        if(mp[sec[index]]==1) mp.erase(sec[index]);
        if(mp[sec[index]]>1) mp[sec[index]]--;
        sec[index]+=val;
        mp[sec[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(int i=0;i<fir.size();i++){
            // cout<<sec[i]<<" ";
            // auto it= mp.find(tot-sec[i]);
            
            if(mp[tot-fir[i]]>0){
                ans+=mp[tot-fir[i]];
                // cout<<" I="<<it->first<<it->second<<" ";
            }
        }
        // cout<<endl;
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */