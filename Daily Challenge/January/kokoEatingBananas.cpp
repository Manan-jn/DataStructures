//875. Koko Eating Bananas
//20th January

class Solution {
public:
    
    bool canSheEatAll(vector<int>piles,int h,int k,int n){
        int i=0;
        int time =0;
        int count =0;
        for(int i=0;i<n;i++){
            count += (piles[i]/k);
            if(piles[i]%k>0){
                count+=1;
            }    
        }
        if(count<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int maxRange = piles[n-1];
        //we can have k from 1 to maxRange
        //we need to check if we can have a speed of mid and can eat all 
        // then she can eat for values greater than mid also
        // so look back before mid
        int s =1;
        int e = maxRange;
        int ans =0;
        while(s<=e){
            int mid = (s+e)/2;
            bool canSheEat = canSheEatAll(piles,h,mid,n);
            if(canSheEat==true){
                ans = mid;
                e = mid-1;
            }
            else{
                s= mid+1;
            }
        }
        return ans;
    }
};