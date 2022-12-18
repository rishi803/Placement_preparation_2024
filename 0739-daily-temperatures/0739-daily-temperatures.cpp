class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> s;
        vector<int> ans(temp.size());
        for(int cur = 0; cur < temp.size(); cur++) {
            while(s.size() and temp[cur] > temp[s.top()]) {    // pop till current temp < stack's top's temp. This maintains monotonic stack
                ans[s.top()] = cur - s.top();           // cur day will be next warmer day for each element that's popped
                s.pop();
            }
            s.push(cur);                                // push onto stack to find next warmer day for cur later on
        }
        return ans;
    }
};