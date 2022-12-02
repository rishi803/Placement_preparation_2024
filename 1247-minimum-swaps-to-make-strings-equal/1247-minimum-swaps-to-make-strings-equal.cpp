// 4 match bnenge (x,x) (x,y) (y,x) (y,y) 
// mismatch honge (s1 ka "x" aur s2 ka "y") (s1 ka "y" aur s2 ka "x")
// agr (s1 ka "x" aur s2 ka "y") 
//     (s1 ka "x" aur s2 ka "y")  to 1 swap me equal ho jayenge

// // agr (s1 ka "y" aur s2 ka "x") 
//     (s1 ka "y" aur s2 ka "x")  phir bhi 1 swap me equal ho jayenge

// baki 2 lgenge har 1 mismatch ke liye

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1.size()!=s2.size()) return -1;
        int xy=0,yx=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='x' and s2[i]=='y') xy++;
            else if(s1[i]=='y' and s2[i]=='x') yx++;
        }
        if((xy+yx)%2!=0) return -1;
        return ((xy/2)+(yx/2)+((xy)%2)*2);
    }
};