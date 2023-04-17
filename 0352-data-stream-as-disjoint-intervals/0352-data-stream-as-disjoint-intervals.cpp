class SummaryRanges {
public:
   
set<int> nums;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
      vector<vector<int>> intervals;
        int start = -1;
        int end = -1;
        for (auto num : nums) {
            if(end < 0)
                start = end = num;
            else if (num - end == 1) {
                end = num;
            } else {
                intervals.push_back({start, end});
                start = end = num;
            }
        }
        if(start!=-1 and end!=-1)
        intervals.push_back({start, end});
        return intervals;

    }
};

