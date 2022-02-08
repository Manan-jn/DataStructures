//258. Add Digits
//Leetcode 8th Feb

class Solution {
public:
    int check(int sum){
        if(sum/10==0){
            return sum;
        }
        int digits =0;
        while(sum!=0){
            digits+= sum%10;
            sum = sum/10;
        }
        return check(digits);
    }
    int addDigits(int num) {
        int sum =0;
        while(num!=0){
            sum = sum + num%10;
            num = num/10;
        }
        return check(sum);
    }
};