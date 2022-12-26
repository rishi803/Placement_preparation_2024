class Solution {
public:
    
    bool help(vector<int>&arr, int st){
        if(st<0 or st>=arr.size() or arr[st]<0) return false;
        if(arr[st]==0) return true;
        arr[st]*=-1;
        
       return  help(arr,st+arr[st]) or help(arr,st-arr[st]);
    }
    bool canReach(vector<int>& arr, int start) {
        return help(arr,start);
    }
};