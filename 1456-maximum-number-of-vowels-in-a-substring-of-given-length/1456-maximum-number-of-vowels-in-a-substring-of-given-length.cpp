class Solution {
public:
    bool isv(char a){
        return a=='a' or a=='e' or a=='i' or a=='o' or a=='u';
    }
    int maxVowels(string s, int k) {
     int temp=0,mx=0,head=0,tail=0;
        for(head=0;head<k;head++){
            if(isv(s[head])) temp++;
        }
        mx=max(mx,temp);
      for(head=k;head<s.size();head++){
          if(isv(s[tail])) temp--;
          if(isv(s[head])) temp++;
          mx=max(mx,temp);
          tail++;
      }  
        return mx;
    }
};