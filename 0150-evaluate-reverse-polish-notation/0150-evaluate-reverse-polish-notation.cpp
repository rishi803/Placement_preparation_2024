class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for(auto &it:tokens){
            if(it=="+" or it=="-" or it=="*" or it=="/"){
                long op1=st.top();
                st.pop();
                long op2=st.top();
                st.pop();
                
            if(it == "+") op1 = op2 + op1;
			if(it == "-") op1 = op2 - op1;
			if(it == "/") op1 = op2 / op1;
			if(it == "*") op1 = op2 * op1;   
			st.push(op1);
                
            }
            else{
                
                st.push(stoll(it));
            }
        }
        return st.top();
    }
};