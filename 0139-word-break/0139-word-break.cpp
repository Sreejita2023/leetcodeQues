class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        int w=wordDict.size();
        int l=s.length();
        for(int i=0;i<w;i++){
            mp[wordDict[i]]=2;
        }
        vector<bool>dp(l+1,false);
        dp[0]=true;
        for(int i=1;i<=l;i++){
            for(int start=i-1;start>=0;start-- ){
                 if(dp[start]==true){
                     string d=s.substr(start,i-start);
                     if(mp[d]==2){
                         dp[i]=true;
                         break;
                     }
                 }
            }
        }
        return dp[l];
    }

};