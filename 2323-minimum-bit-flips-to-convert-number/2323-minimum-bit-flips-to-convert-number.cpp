class Solution {
public:
    int minBitFlips(int start, int goal) {
        int middle= start^goal;
        int count=0;
        while(middle>0){
            if(middle%2==1){
                count++;
            }
            middle=middle/2;
        }
        return count;
    }
};