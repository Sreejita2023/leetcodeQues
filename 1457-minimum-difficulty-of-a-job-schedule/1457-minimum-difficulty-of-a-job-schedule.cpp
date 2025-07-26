class Solution {
public:
    int solve(vector<int>& job, int d,int i,vector<vector<int>>&dp){
        int n=job.size();
        if(i==n && d==0){
            return 0;
        }
        if(i==n|| d==0){
            return INT_MAX;
        }
        if(dp[i][d]!=-1)return dp[i][d];
        int maxi=job[i];
        int mini=INT_MAX;
        for(int j=i;j<job.size();j++){
            maxi=max(maxi,job[j]);
            int temp=solve(job,d-1,j+1,dp);
            if(temp!=INT_MAX){
                mini=min(mini,temp+maxi);
            }
        }
        dp[i][d]=mini;
        return dp[i][d];
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d)return -1;
        int n=jobDifficulty.size();
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return solve(jobDifficulty,d,0,dp);
    }
};