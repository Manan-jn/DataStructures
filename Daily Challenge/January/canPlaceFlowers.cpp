//605. Can Place Flowers
//18th January

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int count=0;
        if(n==0){
            return true;
        }
        if(m==1){
            if(flowerbed[0]==1 && n==0 || flowerbed[0]==0 && n==1){
                return true;
            }
            return false;
        }
     
        int temp = n;
        for(int i=0;i<m;i++){
            if(i==0 && m>=2 && flowerbed[i+1]!=1 && flowerbed[i]!=1 && n>0){
                flowerbed[i]=1;
                count++;
                n--;
            }
            else if(i==m-1 && m>=2 && flowerbed[i-1]!=1 && flowerbed[i]!=1 && n>0){
                flowerbed[i]=1;
                count++;
                n--;
            }
            else if(flowerbed[i]==0 && i+1<m && flowerbed[i+1]==0 && flowerbed[i-1]==0 && n>0){
                flowerbed[i]=1;
                count++;
                n--;
            }
        }
        if(count==temp){
            return true;
        }
        return false;
    }
};