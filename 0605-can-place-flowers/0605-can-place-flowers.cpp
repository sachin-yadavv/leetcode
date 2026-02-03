class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s=flowerbed.size();
        int cnt=0;
        for(int i=0;i<s;i++){
            if(flowerbed[i]==0){
         bool left=(i==0 || flowerbed[i-1]!=1);
         bool right=(i==s-1 || flowerbed[i+1]!=1);
            
         if(left && right){
            flowerbed[i]=1;
            cnt++;
         }
        }
        }
        return (cnt>=n);
    }
};