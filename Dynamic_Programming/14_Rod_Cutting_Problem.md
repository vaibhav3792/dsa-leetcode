- Matches with Knapsack
- price[] == val[]
- length[] == wt[]
- N == W (Capacity)
- Note: n = size of price, and price[] is 1-indexed array.

## Code

```cpp

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int> dp(n+1,0);
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=i;j++){
                
                dp[i] = max(dp[i],price[j-1] + dp[i-j]);
            }
        }
        
        return dp[n];
    }
};
```