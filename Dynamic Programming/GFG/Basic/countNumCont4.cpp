class Solution {
  public:
    int countNumberswith4(int N) {
        // code here
        int count =0;
        for(int i=1;i<=N;i++){
            int num = i;
            while(num!=0){
                int temp= num%10;
                if(temp==4){
                    count++;
                    break;
                }
                num= num/10;
            }
        }
        return count;
    }
};