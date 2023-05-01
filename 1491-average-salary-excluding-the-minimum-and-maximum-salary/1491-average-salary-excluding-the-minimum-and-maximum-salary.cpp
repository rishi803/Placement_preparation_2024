class Solution {
public:
    double average(vector<int>& salary) {
        int mn=*min_element(begin(salary),end(salary));
        int mx=*max_element(begin(salary),end(salary));
        
        int total=accumulate(begin(salary),end(salary),0);
        int sz=salary.size()-2;
        
        double ans=  double(total-mn-mx)/sz;
        
        return ans;
    }
};