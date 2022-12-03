class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int group_size) {
         if(hand.size() % group_size != 0) return false;
        map<int, int> mp;
        for(auto i: hand) mp[i]++;  //nlogn operation
        
        while(mp.size()){
            int first = mp.begin() -> first;  //first key of map

            //target is the right limit of current group
            int target = first + group_size - 1;
            
            for(int i = first; i <= target; i++){
                //consecutive ele is not found so return false
                if(mp.count(i) == 0) return false;  //log n operation
                
                else if(--mp[i] == 0) mp.erase(i);  //log n operation
            }        
        }
        
        return true;
    }
};