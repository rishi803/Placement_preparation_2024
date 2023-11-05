class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        stack<int>st;
        stack<int>q;
        unordered_map<int,int>mp;
        
        for(int i=arr.size()-1; i>=0; i--)
        {
            st.push(arr[i]);
        }
        
        while(true){
            
            
            int f= st.top();
        st.pop();
            
            if(st.empty()){
                if(f>= q.top()) return f;
                while(!q.empty()){
                    st.push(q.top());
                    q.pop();
                }
            }
        int s= st.top();
        st.pop();
            
        if(mp[f] >= k) return f;
            
        if(f>s){
            mp[f]++;
            st.push(f);
            q.push(s);
            if(mp[f] >= k) return f;
        }
        else{
            mp[s]++;
            st.push(s);
            q.push(s);
            if(mp[f] >= k) return f;
        }
        }
        return 0;
    }
};