class LUPrefix {
public:
    vector<int>prefix;
    int val=0;
    
    LUPrefix(int n) {
        prefix.resize(n+2,0);
    }
    
    void upload(int video) {
        prefix[video]=1;
    }
    
    int longest() {
        
        while(prefix[val+1]==1) val++;
        return val;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */