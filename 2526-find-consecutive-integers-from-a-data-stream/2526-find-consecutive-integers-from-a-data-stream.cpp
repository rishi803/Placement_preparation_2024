class DataStream {
public:
    int val,lastk,cnt=0;
    vector<int>v;
    
    DataStream(int value, int k) {
        val=value;
        lastk=k;
    }
    
    bool consec(int num) {
        
        if(num==val) cnt++;
        else cnt=0;
        
        if(cnt>=lastk) return true;
        else return false;
        
    }
};

