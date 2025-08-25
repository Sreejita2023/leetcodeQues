class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>prev(n),suff(n),res(n);
        prev[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prev[i]=max(prev[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=min(suff[i+1],nums[i]);
        }
        res[n-1]=prev[n-1];
        for(int i=n-2;i>=0;i--){
            if(prev[i]>suff[i+1]){
                res[i]=res[i+1];
            }
            else{
                res[i]=prev[i];
            }
        }
        return res;
    }
};