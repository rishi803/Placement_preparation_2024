// hme 1 se 1 tk ka distance pr kam krna h

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int left=-1;
        int ans=0;
        for(int i=0;i<seats.size();i++){
            
            if(i==seats.size()-1 and seats[i]==0){
                ans=max(ans,i-left);
            }
            if(seats[i]==0) continue;
            
            if(left==-1){                          
                ans=max(ans,i-0);
                left=i;
            }
            
            else{
                ans=max(ans,(i-left)/2);
                left=i;
            }
            
        }
        return ans;
    }
};