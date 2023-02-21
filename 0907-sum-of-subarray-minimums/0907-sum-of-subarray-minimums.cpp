class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        stack<int>st1,st2;
        vector<int>left_le(arr.size()),right_le(arr.size());
        
        for(int i=0;i<arr.size();i++){
            left_le[i]=arr.size()-i;
        }
     for(int i=0;i<arr.size();i++){
              right_le[i]=i+1;
        }
        for(int i=0;i<arr.size();i++){
            
            while(!st1.empty() and arr[i]<=arr[st1.top()]){
                left_le[st1.top()]=i-st1.top();
                st1.pop();
            }
            
            st1.push(i);
            
        }
        
          for(int i=arr.size()-1;i>=0;i--){
            
            while(!st2.empty() and arr[i]<arr[st2.top()]){
                right_le[st2.top()]=st2.top()-i;
                st2.pop();
            }
            
            st2.push(i);
            
        }
        // for(int i=0;i<arr.size();i++){
        //    cout<<left_le[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<arr.size();i++){
        //    cout<<right_le[i]<<" ";
        // }
       long long ans = 0, mod = 1e9 +7;
    for(int i = 0; i < arr.size(); i++){
      ans = (ans + arr[i]%mod * left_le[i]%mod * right_le[i]%mod)%mod;
    }
        return ans;
    }
};