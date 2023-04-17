class Solution {
public:
    int decimalToBinary(int N)
{
    // To store the binary number
    int B_Number = 0;
    int cnt = 0;
    while (N != 0) {
        int rem = N % 2;
        int c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
        // Count used to store exponent value
        cnt++;
    }
    return B_Number;
}
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        int sz=nums[0].size();
        string ans;
        unordered_map<int,int>mp;
        
        for(auto i:nums){
            int num=stoi(i,0,2);
            mp[num]=1;
        }
        
        int temp;
        for(int i=0;i<(pow(2,sz));i++){
            if(mp.find(i)==mp.end()){
                temp=decimalToBinary(i);
                break;
            }
        }
        // cout<<temp<<endl;
        if(temp==0) return ans.append(sz,'0');
        
       ans=to_string(temp);
        if(ans.size()<sz){
            string rk;
            rk.append(sz-ans.size(),'0');
            return rk+ans;
        
        } 
        return ans;
        
    }
};