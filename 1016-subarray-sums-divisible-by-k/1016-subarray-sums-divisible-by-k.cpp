class Solution {
public:

    
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int total=0;
        for(auto n :nums){
            sum=(sum+n%k+k)%k;
            total+=mp[sum];
            mp[sum]++;
        }
        return total;
    }
};