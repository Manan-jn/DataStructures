//1104. Path In Zigzag Labelled Binary Tree
//Leetcode Medium Binary Tree
class Solution {
public:
    int diff=-1;
    vector<int> pathInZigZagTree(int label) {
        int key = label +1;
        //we need to find min value of h 2^h>=key
        int h=1;
        int temp = 0;
        while(temp<key){
            temp = pow(2,h);
            h++;
        }
        int height = h-1;
        vector<int>vect;
        while(height>0){
                if(height%2==0){
                    if(diff==-1){
                        diff = pow(2,height)-1-label;
                    }
                    else{
                        label = pow(2,height)-1-(diff/2);
                        diff= diff/2;
                    }
                    vect.push_back(label);
                }
                else{
                    if(diff==-1){
                        diff = (label - pow(2,height-1));
                    }
                    else{
                        if(height!=1){
                            label = pow(2,height-1)+(diff)/2;
                            diff=diff/2;
                        }
                        else{
                            label =1;
                        }
                    }
                    vect.push_back(label);
                }
                height = height-1;
            }
        reverse(vect.begin(),vect.end());
        return vect;
    }
};