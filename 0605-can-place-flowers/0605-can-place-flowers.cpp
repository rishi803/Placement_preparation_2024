class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        if(flowerbed.size()==1) return flowerbed[0]==0;
        
        for(int i=0;i<flowerbed.size();i++){
            
            if(n==0) return true;
            
            if(i==0){
                if(flowerbed[i]==0 and flowerbed[i+1]==0) {n--;
                flowerbed[i]=1;}
            }
            else if(i==flowerbed.size()-1){
                if(flowerbed[flowerbed.size()-2]==0 and flowerbed[flowerbed.size()-1]==0) n--;
            }
            else{
                if(flowerbed[i-1]==0 and flowerbed[i]==0 and flowerbed[i+1]==0) {n--;
                flowerbed[i]=1;}
            }
        }
        if(n==0) return true;
        else return false;
    }
};