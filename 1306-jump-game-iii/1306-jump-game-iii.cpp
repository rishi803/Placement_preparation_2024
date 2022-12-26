class Solution {
public:
    
    bool help(vector<int>&arr, int st){
        if(st<0 or st>=arr.size() or arr[st]<0) return false;
        if(arr[st]==0) return true;
        arr[st]*=-1;                 // mark the index as visited and dont worry it will not effect below code
                                     // beacause sign will interchange only which causes no effect below but very helpful 
                                     // to mark it as visited that dont explore this path by next function because it only 
                                     // ask for true or false not any integer answer.
        
       return  help(arr,st+arr[st]) or help(arr,st-arr[st]);
    }
    bool canReach(vector<int>& arr, int start) {
        return help(arr,start);
    }
};