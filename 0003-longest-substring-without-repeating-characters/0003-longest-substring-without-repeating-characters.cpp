class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0,j=0;int ans=0;
        unordered_map<int,int>mp;
        while(j<n){
           int curr=s[j];
            if(mp.find(curr)==mp.end()){
                mp[curr]++;
                j++;
                ans=max(ans,j-i);
            }
            else{
                mp.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};