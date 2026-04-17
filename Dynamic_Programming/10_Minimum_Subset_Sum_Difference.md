## Minimum Subset Sum Difference

- Let's say an array has two subset sums s1 and s2
- We have to find s1 and s2 such that there difference is minimum
- s2-s1 = Range-2s1 (where Range = s1+s2)
- Range is sum of all elements in the array
- s1 can vary between 0 to Range 

## Code
```cpp
class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int sumTotal = 0;

    for (int num : arr) {
        sumTotal += num;
    }

    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(sumTotal + 1, 0));


    dp[0][0] = 1;


    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= sumTotal; sum++) {
          
        
            dp[i][sum] = dp[i-1][sum];

            if (sum >= arr[i-1]) {
                dp[i][sum] = dp[i][sum] || dp[i-1][sum - arr[i-1]];
            }
        }
    }


    int minDiff = INT_MAX;

    for (int sum = 0; sum <= sumTotal / 2; sum++) {
        if (dp[n][sum]) {
            minDiff = min(minDiff, abs((sumTotal - sum) - sum));
        }
    }

    return minDiff;
    }
};

```