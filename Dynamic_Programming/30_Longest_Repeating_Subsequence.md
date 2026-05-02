- For the subsequence to repeat the letters should appear atleast 2 times in the string
- For this they have to appear at different indices so we will add that as a restriction in the standard LCS Code

## Code

```cpp
if(a[i-1]==b[j-1] && i!=j){
    dp[i][j] = 1 + dp[i-1][j-1];
    i--;
    j--;
}else{
    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
}

```