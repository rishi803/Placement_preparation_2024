class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        long long sum=accumulate(skill.begin(),skill.end(),0ll);
        sort(skill.begin(),skill.end());
         long long ans=0;
        // vector<pair<int,int>>v;
        int team=skill.size()/2;
        long long target=sum/team;
        
        int i=0,j=skill.size()-1,cnt=0;
        // cout<<target<<endl;
        while(i<j){
            if(skill[i]+skill[j]==target){
                cnt++;
                 ans+=(skill[i]*skill[j]);
                 i++;
                j--;
            }
            else if(skill[i]+skill[j]>target){
                j--;
                
            }
            
            else{
                i++;
            }
        }
        
       
        
        if (cnt<skill.size()/2) return -1;
      
        return ans;
        
        
    }
};