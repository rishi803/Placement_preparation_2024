class CountIntervals {
public:
     set<pair<int, int>> st;
     int cnt;
    CountIntervals() {
        cnt = 0;
    }
    
    void add(int left, int right) {
        auto it = st.lower_bound({left, right});
        
        if(it != st.begin() && (--it)->second < left) { // left,right jha pr insert hoga vaha agr vo beginning h to koi na uska age vale elements se check krenge overlap lkin agr beginning ke bad ka koi h to just piche vale se overlap check krenge kunki baki piche ke elements bina overlap ke hi insert kiye hue h ( ab doubt a skta h to ki agr--> (1,2) (3,8) (16,19) (20,25) me (4,30) insert krna h to dhyan do lower bound vhi position dega jha iski phli occurence honi chahiye mtlb (3,8) ke bad aur isi se overlap ki probability ho skti hai bas lkin age ye sare element se overlap check krega jo niche kiya gaya h)
            ++it;
        }
        
        while(it != st.end() and it->first<=right) {
            left = min(left, it->first);
            right = max(right, it->second);
            
            cnt -= (it->second - it->first + 1);
            it = st.erase(it);
        }
        
        st.insert({ left, right });
        cnt += (right - left + 1);
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */