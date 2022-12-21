class Solution {
    public boolean isPowerOfTwo(int n) {
         long a=n;
        if(a==0) return false;
        if((a&(a-1))==0) return true;
        else return false;
    }
}