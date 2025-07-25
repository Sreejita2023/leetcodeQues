class Solution {
public:
    vector<vector<int>> ans;
    void solve(int sum, vector<int>& nums, int i, int target,
               vector<int> curr) {
        if (target == sum) {
            ans.push_back(curr);
            return;
        }
        if (target < sum) {
            return;
        }
        if (i  == nums.size()) {
            return;
        }
        if (sum + nums[i] <= target) {
            curr.push_back(nums[i]);
            solve(sum + nums[i], nums, i, target, curr);
            curr.pop_back();
        }
        solve(sum, nums, i + 1, target, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(0, candidates, 0, target, curr);
        return ans;
    }
};