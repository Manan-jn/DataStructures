//73. Set Matrix Zeroes
//Leetcode Medium Hashmaps

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,vector<int>>mp;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    mp[i].push_back(j);
                }
            }
        }
        for(auto x:mp){
            int currRow = x.first;
            vector<int>temp = x.second;
            for(int currCol = 0;currCol<temp.size();currCol++){
                for(int i=0;i<cols;i++){
                    matrix[currRow][i]=0;
                }
                for(int i=0;i<rows;i++){
                    matrix[i][temp[currCol]] =0;
                }
            }
        }
        return;
    }
};