class Solution {
public:
      bool isans(vector<int>&temp, int n, int k, int mn) { 
      int cnt = 1;
      int last = temp[0];
      for (int i = 1; i < n; i++) {  
        if (temp[i] - last >= mn) {
          cnt++;
          last = temp[i];
        }
      }
      if (cnt >= k) return true;
      return false;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        
      sort(price.begin(), price.end());
        
      int n=price.size();
      int l = 1;     // decide lower range 
      int  h = price[n - 1] - price[0];  // decide upper range
  
      int ans=0;
        
      while (l <= h) {            // do binary search 
        int mid = (l + h)/ 2;

        if (isans(price, n, k, mid)) {
          ans=mid;
          l = mid + 1;
        } else {
          h= mid - 1;
        }
      }
      
          return ans;
    }
};