class Solution {
public:
   bool haveConflict(vector<string>& event1, vector<string>& event2) {
       
       if(event1[1]<event2[0] and event1[0]<event2[1]) return false;
       else if(event1[1]>event2[0] and event1[0]>event2[1]) return false;
       else return true;
    }
};