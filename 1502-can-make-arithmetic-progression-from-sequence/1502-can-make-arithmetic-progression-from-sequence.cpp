class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int cnt=0;
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size()-1;i++){
            if(abs(arr[i]-arr[i-1])==abs(arr[i+1]-arr[i])) cnt++;
            else return false;
        }
        return true;
    }
};