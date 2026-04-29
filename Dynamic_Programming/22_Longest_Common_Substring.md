- Parent : LCS
- Input and Output format are the same
- Discontinuity -> Turn the length to 0

## Code

```cpp
int n = s1.length();
int m = s2.length();
vector<vector<int>> dp(n+1,vector<int>(m+1,0));
int res = 0;

for(int i =1;i<=n;i++){
    for(int j = 1;j<=m;j++){
        if(s1[i-1]==s2[j-1]){
            dp[i][j] = 1 + dp[i-1][j-1];
            res = max(res,dp[i][j]);
        } else{
            dp[i][j] = 0;
        }
    }
}

return res;
```