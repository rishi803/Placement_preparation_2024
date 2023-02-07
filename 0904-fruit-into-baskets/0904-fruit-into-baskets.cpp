class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        ; 
        unordered_map<int,int>mp ;      // if necessity to use data structure then use (to store frequency)
        int head=0,tail=0,fruitcnt=0;    // declaration of global variables
        
        for(head=0;head<fruits.size();head++){   // scanning fruits array
            
            mp[fruits[head]]++;
                             
            
            while(mp.size()>2){                // if condition fails go inside while loop to make it true
                
                mp[fruits[tail]]--;
                if(mp[fruits[tail]]==0) mp.erase(fruits[tail]);
                tail++;                      // update tail
            }
            
            fruitcnt=max(fruitcnt,head-tail+1);  // update the answer
        }
        
        return fruitcnt;             // return answer
    }
};