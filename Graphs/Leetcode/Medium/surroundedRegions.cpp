//130. Surrounded Regions
//Leetcode Medium Graphs

class Solution {
public:
    int m=0;
    int n=0;
    void dfs(vector<vector<char>>&board,int i,int j){
        if(i<0 || i>m-1 ||j<0 || j>n-1){
            return;
        }
        if(board[i][j]!='O'){
            return;
        }
        board[i][j]='#';
        
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
        return;
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(board[i][j]=='O'){
                        dfs(board,i,j);
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
        return;
        
    }
};