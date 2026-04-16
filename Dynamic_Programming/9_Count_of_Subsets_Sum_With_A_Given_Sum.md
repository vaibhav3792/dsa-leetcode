- Subset Sum -> Count number of subset
- Return type: Bool -> int
- n ka matlab hai ki kitna elements array se le rahe hai -> isliye 0 se n tak ka matrix me use hoga
- Similarly for sum.
---

## Code

```cpp
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        
        dp[0][0] = 1;
        
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<target+1;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=arr[i-1]){
                dp[i][j] += dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[n][target];
        
    }
};
```