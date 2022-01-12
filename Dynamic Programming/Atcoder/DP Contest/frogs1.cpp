//A - Frog 1
//Atcoder Problem 1

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 1e5;
int h[N], memo[N];

//Top Down Approach
int func(int n){
    if(n==0) return 0;
    int &ans = memo[n];

    if(ans!=-1) return ans;
    ans = func(n-1)+ abs(h[n-1]-h[n]);
    if(n-2>=0) ans = min(ans,func(n-2) + abs(h[n-2]-h[n]));
    return ans;
}

//Top Down Approach
int findMinCostTD(int n,int *height,int*dp){
    if(n==0 || n==1){
        return dp[n];
    }
    if(dp[n]!=0){
        return dp[n];
    }
    dp[n]=  min(abs(height[n]-height[n-1])+findMinCostTD(n-1,height,dp),
                    abs(height[n]-height[n-2])+findMinCostTD(n-2,height,dp));
    return dp[n];
}

//Bottom Up Approach
int findMinCostBU(int n,int *height){
    vector<int>dp(n,0);
    dp[0]=0;
    dp[1]= abs(height[1]-height[0]);
    for(int i=2;i<n;i++){
        dp[i]= min(abs(height[i]-height[i-1])+dp[i-1],abs(height[i]-height[i-2])+dp[i-2]);
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    int height[n];
    for(int i=0;i<n;i++){
      cin>>h[i];
    }
    int dp[n]={0};
    dp[0]=0;
    dp[1]=abs(height[1]-height[0]);
    memset(memo,-1,sizeof(memo));
    cout<<func(n-1)<<endl;
    return 0;
}