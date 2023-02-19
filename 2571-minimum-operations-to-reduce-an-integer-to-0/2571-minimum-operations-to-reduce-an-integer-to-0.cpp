class Solution {
public:
   int minOperations(int n) {
        int res = 0;
        while (n > 0) {
            if ((n & 3) == 3) {
                n++;
                res++;
                // cout<<n<<endl;
            } else {
                res += n & 1;
                n >>= 1;
                // cout<<n<<endl;
            }
        }
        return res;
    }
};