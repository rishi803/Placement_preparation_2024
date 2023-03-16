class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {  // ex-  -1 -8 0 5 -9
        
        sort(sat.begin(),sat.end());    // -9 -8 -1 0 5
        
        int totalsum=0,ans=0,time=1;
        
        for(int i=0;i<sat.size();i++){
            
            if(sat[i]>=0){                // you have to take all the positive elements in answer
                totalsum+=sat[i];        // final totalsum= 0+5=5
                ans+=sat[i]*time;        // ans= 0*1 + 5*2 = 10
                time++;   
            }
        }
        
        int temp=0,prevsum=totalsum;
        
        reverse(sat.begin(),sat.end());   // reverse so that -1 comes before -9 (-smaller value phle answer me  consider krna  i.e  5 0 -1 -8 -9)
        
        for(int i=0;i<sat.size();i++){
            
            if(sat[i]<0){    // for (-1 -8 -9)  (0,5 i.e positive elements we have already taken)
                
                temp=sat[i]; 
                if(ans+prevsum+temp>=ans){  // on considering this current -ve element what would be our answer it would be -1*1 + 0*2 + 5*3 = 14  so here a small trick instead of computing it again we are doing ans=ans + prevsum + this current -ve element i.e ans=(10+5-1) = 14
                    ans=ans+prevsum+temp;
                    prevsum+=temp;  // updating prevsum by adding current -ve element to it because this -ve element has contributed in finding max answer
                }
            }
        }
        
        return ans;
    }
};