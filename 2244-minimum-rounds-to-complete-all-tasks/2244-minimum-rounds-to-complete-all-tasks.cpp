class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int mn=0;
       unordered_map<int,int>m;
        for(auto &it:tasks){
            m[it]++;
        }
        for(auto &[fir,sec]:m){
            while(sec%3!=0){
                if(sec==1) return -1;
                sec-=2;
                mn++;
            }
            if(sec%3==0){
                mn+=sec/3;
            }
        }
        return mn;
    }
};