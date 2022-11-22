

class Solution {
public:
    int nextGreaterElement(int n) {
      string temp=to_string(n);
      next_permutation(temp.begin(),temp.end());
      int res=stol(temp);
      return (res<=n or res>INT_MAX)?-1:res;
    }
};