#define max(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), result = 0;
        map <int, int> sumToIndex;
        vector< vector<int> > dp(n + 1, vector<int>(2));
        for (int i = 1; i <= n; ++i)
        {
            if (nums[i - 1] == 0)
            {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1];
            }
            else
            {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + 1;
            }
            if (dp[i][0] == dp[i][1])
                result = max(result, dp[i][0] * 2);
            else
            {
                int dif = dp[i][1] - dp[i][0];
                if (!sumToIndex.count(dif))
                    sumToIndex[dif] = i;
                else
                    result = max(result, 2 * (dp[i][0] - dp[sumToIndex[dif]][0]));
            }
        }
        return result;
    }
};