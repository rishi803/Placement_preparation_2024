class SmallestInfiniteSet {
public:
    
    set<int>st;
    int sm=1;
    
    SmallestInfiniteSet() {
       
    }
    
    int popSmallest() {
      if(!st.empty()){
          int small=*st.begin();
          st.erase(st.begin());
          return small;
      }
        else{
            return sm++;
        }
    }
    
    void addBack(int num) {
        
        if(num<sm) st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */