class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K - 1);
    }
    int atMostK(vector<int>& A, int k) {
        int tail = 0, res = 0;
        unordered_map<int, int> count;
        for (int head = 0; head < A.size(); ++head) {
            
            count[A[head]]++;
            
            while(count.size()>k){
                count[A[tail]]--;
                if(count[A[tail]]==0) count.erase(A[tail]);
                tail++;
            }
            res+=head-tail+1;
            
        }
        return res;
    }
};