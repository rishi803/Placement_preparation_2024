class Solution {
public:
    string multiply(string num1, string num2) {
        
        
        
        vector<int>pre(num1.size()+num2.size());
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        
        
        for(int i=0;i<num1.size();i++){
            int number1=num1[i]-'0';
            int carry = 0;
            for(int j=0;j<num2.size();j++){
                int number2= num2[j]-'0';
                int product= number1*number2;
                int finalnum= product + carry + pre[i+j];
                
                pre[i+j]= (finalnum)%10;
                carry= finalnum/10;
               
            }
            if(carry) pre[i+num2.size()]=carry;
            
            
        }
        reverse(pre.begin(),pre.end());
        
        string ans;
        
        for(auto i=0;i<pre.size();i++){
            if(ans.empty() and pre[i]==0) continue;
            else ans+=to_string(pre[i]);
        }
        
        return ans.size()>0?ans:"0";
    }
};