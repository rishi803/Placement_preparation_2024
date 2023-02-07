class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int head=0,tail=0,fruitcnt=0;
        
        for(head=0;head<fruits.size();head++){
            
            mp[fruits[head]]++;
            
            while(mp.size()>2){
                mp[fruits[tail]]--;
                if(mp[fruits[tail]]==0) mp.erase(fruits[tail]);  
                tail++;
            }
            
            fruitcnt=max(fruitcnt,head-tail+1);
        }
        
        return fruitcnt;
    }
};