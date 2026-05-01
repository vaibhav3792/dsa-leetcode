-  Lets say we have two strings geek and eke, then its shortest common supersequence will be geeke as it has both -- geek and eke.
- We have to return the length of geeke that is 5 as the output.
- A simple way to calculate the supersequence would be to add the two strings but we want the shortest one, so we will remove the subsequence that is common in both.
- We will use the code for LCS for that and just change the last line.

## Code

```cpp

int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return n + m - dp[n][m];

```