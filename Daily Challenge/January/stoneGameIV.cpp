//1510. Stone Game IV
//22nd January

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<long long int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        for(long long int i=2;i<=n;i++){
            //mark the square of i position which is less than n a winning pos
            //subtract the nearest square number and check the remaining pos 
            //if it is a win then make it loose
            //if it is a loose then make it a win
            if(i*i<=n){
                dp[i*i]=1;
            }
            
            long long int count =1;
            while(count*count<=i){
                int temp = dp[i-count*count];
                if(temp==0){
                    dp[i]=1;
                    break;
                }
                count++;
            }
        }
        if(dp[n]==1){
            return true;
        }
        return false;
    }
};