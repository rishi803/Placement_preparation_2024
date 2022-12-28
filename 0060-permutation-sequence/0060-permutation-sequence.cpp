class Solution {
public:
    
    string getPermutation(int n, int k) {
        if(n==1) return to_string(n);
        vector<long long>fact(10,1);
        
        for(int i=1;i<=9;i++){
            fact[i]=i*fact[i-1];
        }
        
        string temp;
        
        for(int i=1;i<=n;i++){
            temp+=to_string(i);
        }
        int idx,times;
       
        int temp1= k%(fact[n-1]);
        
        if(temp1==0){
            idx=fact[n-1]-1;
            times=(k/(fact[n-1])-1);
        }
        else{
            idx=temp1-1;
            times=k/(fact[n-1]);
        }
        vector<string>ans;
        ans.push_back(temp);
        for(int i=1;i<fact[n-1];i++){
            next_permutation(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        int idx1=-1,idx2=-1;
       char x='1',y='2';
        while(times--){
            for(int i=0;i<ans[idx].size();i++){
                if(ans[idx][i]==x) idx1=i;
                if(ans[idx][i]==y) idx2=i;
            }
            if(idx1!=-1 and idx2!=-1) swap(ans[idx][idx1],ans[idx][idx2]);
            x++;
            y++;
        }
        return ans[idx];
    }
};