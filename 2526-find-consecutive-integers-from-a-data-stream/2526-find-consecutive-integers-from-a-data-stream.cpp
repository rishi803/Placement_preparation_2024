class DataStream {
public:
    int val,lastk,cnt=0;
    
    DataStream(int value, int k) {
        val=value;
        lastk=k;
    }
    
    bool consec(int num) {
        
        if(num==val) cnt++;
        else cnt=0;
        
        if(cnt>=lastk) return true;   // check whether  last k integers are equal to value
        else return false;
        
    }
};

