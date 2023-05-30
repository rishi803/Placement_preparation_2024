class MyHashSet {
public:
    
    unordered_set<int>st;
    
    MyHashSet() {
        
    }
    
    void add(int key) {
        st.insert(key);
    }
    
    void remove(int key) {
        auto it=st.find(key);
        if(it!=st.end()) st.erase(it);
    }
    
    bool contains(int key) {
        auto it=st.find(key);
        if(it!=st.end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */