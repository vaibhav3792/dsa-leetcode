- Similar as previous Q
- Find LPS and then delete the remaining characters
- Length of LPS is inversely proportional to number of deletions

## Code

```cpp
int n = s.length();
        string a = s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(s[i-1]==a[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return n-dp[n][n];
```