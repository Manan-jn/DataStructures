//63. Unique Paths II
//Leetcode Medium DP

class Solution {
public:
    int findWays(int row,int col,vector<vector<int>> &obstacleGrid){
        //base case
        //if the starting element is an obstacle
        if(obstacleGrid[0][0]==-1){
            return 0;
        }
        //rest find the 1st row
        for(int i=0;i<col;i++){
            if(obstacleGrid[0][i]==-1){
                break;
            }
            obstacleGrid[0][i]=1;
        }
        //rest find the 1st col
        for(int i=0;i<row;i++){
            if(obstacleGrid[i][0]==-1){
                break;
            }
            obstacleGrid[i][0]=1;
        }
        //look for the rest of the grid
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(obstacleGrid[i][j]==-1){
                    continue;
                }
                obstacleGrid[i][j]=0;
                if(obstacleGrid[i][j-1]!=-1){
                    obstacleGrid[i][j]= obstacleGrid[i][j-1];
                }
                if(obstacleGrid[i-1][j]!=-1){
                    obstacleGrid[i][j] = obstacleGrid[i][j]+ obstacleGrid[i-1][j];
                }
            }
        }
        if(obstacleGrid[row-1][col-1] == -1){
            return 0;
        }
        return obstacleGrid[row-1][col-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        vector<int>temp = obstacleGrid[0];
        int col = temp.size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(obstacleGrid[i][j]==1){
                    obstacleGrid[i][j]=-1;
                }
            }
        }
        return findWays(row,col,obstacleGrid);
    }
};