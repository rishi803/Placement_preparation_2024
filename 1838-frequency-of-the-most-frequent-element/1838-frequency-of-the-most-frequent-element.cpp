class Solution {
public:
      int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long head = 0,tail=0, N = A.size(), ans = 0, sum = 0;
        for (head = 0; head < N; ++head) {
            sum += A[head];
            while((head - tail+ 1) * A[head] - sum > k){
                sum-=A[tail];
                tail++;
            }
            ans=max(ans,head-tail+1);
        }
        return ans;
    }
};