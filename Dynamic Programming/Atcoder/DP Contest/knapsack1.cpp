#include<iostream>
#include<cstring>
using namespace std;
#define int long long int

int n,W;
int w[100];
int v[100];
int dp[100][100001];

//Knapsack Problem Brute force approach Time Complexity: O(2^N)
int knapsackBrute(int index,int weight){
    //Base case if the value of index gets more than the elements
    if(index>=n){
        return 0;
    }
    //If we dont include the element
    int ans = knapsackBrute(index+1,weight);

    //If we include the element
    if(w[index]+weight<=W){
        ans = max(ans,knapsackBrute(index+1,weight+w[index])+v[index]);
    }
    return ans;
}

//Knapsack Optimised Approach
//Brute force with memoisation
//Time: index*weight 100*10^5 = 10^7
int knapsackOpt(int index,int weight){
    //base case
    if(index>=n){
        return 0;
    }
    int &ans = dp[index][weight];
    ans = knapsackOpt(index+1,weight);
    if(w[index]+weight<=W){
        ans = max(ans, knapsackOpt(index+1,w[index]+weight)+v[index]);
    }
    return ans;
}


int32_t main(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    // cout<<knapsackBrute(0,0)<<endl;
    memset(dp,0,sizeof(dp));
    cout<<knapsackOpt(0,0)<<endl;
    return 0;
}