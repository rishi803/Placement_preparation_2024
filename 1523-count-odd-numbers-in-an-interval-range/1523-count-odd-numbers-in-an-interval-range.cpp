class Solution {
public:
    int countOdds(int low, int high) {
        
        if(low&1){
            int temp=(high-low+1);
            if(temp%2==0) return temp/2;
            else return temp/2 + 1;
        }
        return (high-low+1)/2;
    }
};