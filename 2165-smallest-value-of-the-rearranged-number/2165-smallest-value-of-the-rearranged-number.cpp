class Solution {
public:
    long long smallestNumber(long long num) {
        
        string s=to_string(abs(num)); //long long to string
        sort(s.begin(),s.end()); // sort the string
        int i=0;
        long long res;
        if(num<=0){ //if negetive number
            reverse(s.begin(),s.end());  // reverse the string
            res= -stol(s); //string to long long
        }
        else{ // if positive
            while(s[i]=='0'){ //come upto first non zero number
                i++;
            }
            swap(s[0],s[i]); // now swap first digit with first non zero number
            res= stol(s); //string to long long 
        }
        return res;
    }
};