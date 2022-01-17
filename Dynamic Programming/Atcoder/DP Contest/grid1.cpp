//H - Grid 1
//Atcoder Problem

#include<iostream>
#include<vector>
using namespace std;

#define mod 1000000007

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>path(h,vector<char>(w,'.'));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>path[i][j];
        }
    }
    vector<vector<int>>dp(h,vector<int>(w,0));
    dp[0][0]=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                if(path[i][j]=='.'){
                    dp[i][j]+=dp[i][j-1];
                }
            }
            else if(j==0){
                if(path[i][j]=='.'){
                    dp[i][j]+=dp[i-1][j];
                }
            }
            else{
                if(path[i][j]=='.'){
                    dp[i][j]=(dp[i][j]+(dp[i-1][j]+dp[i][j-1]))%mod;
                }
            }
        }
    }
    if(path[h-1][w-1]!='#'){
        cout<<dp[h-1][w-1]<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
    return 0;
}