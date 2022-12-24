class Solution {
public:
    string countAndSay(int n) {
        string temp="1";
        int i=0;
        for(int go=2;go<=n;go++){
            string dummy;
            for(int i=temp.size()-1;i>=0;i--){
                dummy+=temp[i];
                int cnt=1;
            while(i>0 and temp[i]==temp[i-1]){
                cnt++;
                 i--;
            }
                dummy+=to_string(cnt);
        }
            temp=dummy;
            reverse(temp.begin(),temp.end());
            
      }
        return temp;
    }
};