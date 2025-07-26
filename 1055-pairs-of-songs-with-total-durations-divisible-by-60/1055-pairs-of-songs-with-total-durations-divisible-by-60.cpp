class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
       unordered_map<int,int>mp;
       int curr=time[0];
       int ans=0;
       int m=60;
       mp[((m-(curr%m))%m)]++;
       for(int j=1;j<time.size();j++){
           curr=time[j];
           int b=curr%m;
           if(mp.find(b)!=mp.end()){
             ans+=mp[b];
           }
            mp[((m-(curr%m))%m)]++;
       }
       return ans;
    }
};