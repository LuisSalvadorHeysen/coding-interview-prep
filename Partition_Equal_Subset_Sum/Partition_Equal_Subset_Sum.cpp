// https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = int(nums.size());
        for (int x : nums) sum += x;
        if (sum % 2 != 0) return false;

        sum /= 2;

        // dp[sum][i] = can we make add up to sum using the first i elements
        vector<vector<bool>> dp(sum + 1, vector<bool>(n + 1));
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = true;
        }

        for (int s = 1; s <= sum; ++s) {
            for (int i = 1; i <= n; ++i) {
                dp[s][i] = (dp[s][i - 1] || (s - nums[i - 1] >= 0 && dp[s - nums[i - 1]][i - 1]));
            }
        }

        return dp[sum][n];
    }
};
