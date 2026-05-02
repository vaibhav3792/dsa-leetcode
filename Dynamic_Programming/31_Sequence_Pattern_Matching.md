- Based on LCS
- If the LCS of the two strings is equal to string a, then return true
- We only need the length to check not the whole string as an equal length means that the smaller string is completely present in larger string


## Code

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        if(n==dp[n][m]) return true;
        return false;
    }
};
```