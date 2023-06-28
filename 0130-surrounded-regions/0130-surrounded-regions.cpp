// dfs at boundary

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&board,int row,int col){
        if(i<0 or i>=row or j<0 or j>=col or board[i][j]!='O') return;
        board[i][j]='@';
        dfs(i,j+1,board,row,col);
        dfs(i+1,j,board,row,col);
        dfs(i-1,j,board,row,col);
        dfs(i,j-1,board,row,col);
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        // dfs traversal at first row and last row
        for(int i=0;i<row;i++){
           if(board[i][0]=='O') dfs(i,0,board,row,col);
            if(board[i][col-1]=='O') dfs(i,col-1,board,row,col);
        }
        // dfs traversal at first column and last column
        for(int j=0;j<col;j++){
            if(board[0][j]=='O') dfs(0,j,board,row,col);
            if(board[row-1][j]=='O') dfs(row-1,j,board,row,col);
        }
        // now the 'O' that are connected to boundary 'O' can not be flipped so only flip those 'O' which is not connected to boundary 'O'
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(board[i][j]=='O') board[i][j]='X';
               if(board[i][j]=='@') board[i][j]='O';
               
           }
       } 
    }
};