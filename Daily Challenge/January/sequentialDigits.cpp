//1291. Sequential Digits
//23rd January

class Solution {
public:
    vector<int>res;
    void performDigits(int start,int low,int high){
        if(start>high){
            return;
        }
        int last = start%10;
        if(last==0 || last==9){
            return;
        }
        start= (start*10)+(last+1);
        if(start>=low && start<=high){
            res.push_back(start);
        }
        performDigits(start,low,high);
        return;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        for(int start =1;start<9;start++){
            performDigits(start,low,high);
        }
        sort(res.begin(),res.end());
        return res;
    }
};