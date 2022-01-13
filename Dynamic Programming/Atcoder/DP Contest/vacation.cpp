//C - Vacation 
//Atcoder Problem 3

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxPoints(int n,vector<vector<int>>&points){
    vector<vector<int>>dp(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            if(i==0){
                dp[i][j]= points[i][j];
            }
            else{
                int value = INT_MIN;
                for(int temp = 0; temp<3;temp++){
                    if(temp!=j){
                        value = max(value,dp[i-1][temp]);      
                    } 
                }
                dp[i][j]= points[i][j]+ value;
            }
        }
    }
    int maxHappiness = 0;
    for(int j=0;j<3;j++){
        maxHappiness= max(maxHappiness,dp[n-1][j]);
    }
    return maxHappiness;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>points(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>points[i][j];
        }
    }
    cout<<maxPoints(n,points)<<endl;
    return 0;
}