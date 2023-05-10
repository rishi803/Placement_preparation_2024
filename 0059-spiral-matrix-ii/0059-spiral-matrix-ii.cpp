class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int top=0,down=n-1,left=0,right=n-1;
        int dir=1,val=0;
        while(left<=right and top<=down){
           
            if(dir==1){
                for(int i=left;i<=right;i++){
                    ans[top][i]=++val;
                   
                }
                    dir=2;
                    top++;
                
            }
           else if(dir==2){
                for(int i=top;i<=down;i++){
                    ans[i][right]=++val;}
                    dir=3;
                    right--;
                
            }
            else  if(dir==3){
                for(int i=right;i>=left;i--){
                   ans[down][i]=++val;}
                    dir=4;
                    down--;
                
            }
            else  if(dir==4){
                for(int i=down;i>=top;i--){
                    ans[i][left]=++val;}
                    dir=1;
                    left++;
                
            }
        }
        return ans;
    }
};