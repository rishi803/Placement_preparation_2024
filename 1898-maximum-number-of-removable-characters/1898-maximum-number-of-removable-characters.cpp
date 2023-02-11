class Solution {
public:
    
    bool isSubsequence(string &s1,string &s2, vector<int>&vis){
        
        int i=0,j=0;
        
        while(i<s1.size() and j<s2.size()){
            
            if(s1[i]==s2[j] and vis[i]==0) j++;
            i++;
        }
        
        return j==s2.size();
    }
    
    bool isValid(string s,string p,int mid,vector<int>rem){
        
        vector<int>vis(s.size(),0);
        
        for(int i=0;i<mid;i++){
            vis[rem[i]]=1;
        }
        
        return isSubsequence(s,p,vis);
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        
        int low=0;
        int high=removable.size();
        
        int ans=0;
        
        while(low<=high){
            
            int mid= low+(high-low)/2;
            
            if(isValid(s,p,mid,removable)){
                ans=mid;
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};