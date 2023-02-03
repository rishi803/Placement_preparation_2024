class Solution {
public:
    int minimumPartition(string s, int k) {
        long long number=0,cnt=1;
        for(int i=0;i<s.size();i++){
            int num=s[i]-'0';
            if(num>k) return -1;
            number=number*10+num;
            
            if(number>k){
                number%=10;
                cnt++;
            }
        }
        return cnt;
    }
};