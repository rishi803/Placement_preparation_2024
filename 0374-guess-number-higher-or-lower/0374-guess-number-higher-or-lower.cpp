
class Solution {
public:
   static int guessNumber(const int n) {
        int lo = 1;
        int hi = n;
        while (lo <= hi) {
            const int mid = lo + (hi - lo) / 2;
            const int g = guess(mid);
            if (g == 0) {
                return mid;
            } else if (g == -1) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        // unreachable
        assert(false);
        return -1;
    }
};