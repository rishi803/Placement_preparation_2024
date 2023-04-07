class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int ans=0,prev=1;
        vector<int>temp(ratings.size(),1);
        
        for(int i=1;i<ratings.size();i++){
          if(ratings[i]>ratings[i-1]){
              prev+=1;
              temp[i]=prev;
          }
            else{
                prev=1;
            }
        }
        prev=1;
        
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                prev+=1;
                temp[i]=max(prev,temp[i]);
            }
            else{
                prev=1;
            }
        }
        
        for(auto i:temp) ans+=i;
        return ans;
    }
}; 