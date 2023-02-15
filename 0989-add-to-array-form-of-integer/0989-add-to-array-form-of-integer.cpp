class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       
        int carry=0;
        int i=num.size()-1;
        vector<int>ans;
        
        while(i>=0 or k>0 or carry){
            
            int num1=0,num2=0;
            
            if(i>=0){
               num1= num[i];
                i--;
            }
             
            
            if(k>0){
                 num2= k%10;
                    k/=10;  
            }
          
            int sum=num1+num2+carry;
            carry=sum/10;
            
            ans.push_back(sum%10);
            
            
        }
        if(carry) ans.push_back(carry);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};