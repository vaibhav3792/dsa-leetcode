- If the array has two subsets with same sum, let's say 'S' then their total sum should be 2S which will be even
- If we don't get the sum of the whole array as even then we can return False which means that equal sum partition is not possible
- If we get the sum as even then we can check for subset sum with required sum = half of total sum

> Knapsack -> Subset Sum -> Equal Sum Partition

## Code

```cpp
class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
         // Calculate sum of the elements in array
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();

    // If sum is odd, there cannot be two 
    // subsets with equal sum
    if (sum % 2 != 0)
        return false;
        
    sum = sum/2;
    
    // Create a 2D vector for storing results
    // of subproblems
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // If sum is 0, then answer is true (empty subset)
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill the dp table in bottom-up manner
    for (int i = 1; i <= n; i++) {
      
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1]) {
              
                // Exclude the current element
                dp[i][j] = dp[i - 1][j]; 
            }
            else {
              
                // Include or exclude
                dp[i][j] = dp[i - 1][j] 
                || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][sum];
}
    
};
```