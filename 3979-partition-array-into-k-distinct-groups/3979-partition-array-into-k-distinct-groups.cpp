class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto e :nums){
            mp[e]++;
        }
        unordered_map<int,int>::iterator it=mp.begin();
        while(it!=mp.end()){
            if(it->second > n/k){
                return false;
            }
            it++;
        }
        return n%k==0;
    }
};