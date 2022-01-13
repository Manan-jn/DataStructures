//B - Frog 2
//Atcoder Problem 2

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int findMinCost(int n,int k,int*h){
    vector<int>dp(n,0);
    dp[1] = abs(h[1]-h[0]);
    for(int i=2;i<n;i++){
        int temp = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                temp = min(temp,dp[i-j]+ abs(h[i]-h[i-j]));
            }   
        }
        dp[i]= temp;
    }
    return dp[n-1];
}

int main(){
    int n,k;
    cin>>n>>k;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<findMinCost(n,k,h);
    return 0;
}