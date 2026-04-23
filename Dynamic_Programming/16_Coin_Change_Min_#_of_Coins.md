- If we have no coins but we have to get a sum, let's say 1, then we will need an infinite number of coins that we will initialize using INT_MAX - 1
- We use INT_MAX -1 because during tabulation we add + 1 to our value in the array and it will cause Integer Overflow

## Code

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if (n == 0)
            return -1;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX - 1));

        for (int i = 0; i < n + 1; i++) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= amount; j++) {
            if (j % coins[0] == 0) {
                dp[1][j] = j / coins[0];
            } else {
                dp[1][j] = INT_MAX - 1;
            }
        }

        for (int i = 2; i < n + 1; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j >= coins[i - 1]) {
                    dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][amount] == INT_MAX - 1) {
            return -1;
        } else {
            return dp[n][amount];
        }
    }
};
```