- Both in this Q and LCS we have to find subsequence
- The input and output formats match but we only have 1 string for this Q while we need 2 for LCS
- Another string could be derived from the first string
- A palindrome is a string that is the same if read from either way. So if we just reverse the first string and then find LCS. We have our answer.

## Code

```cpp
class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
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
        
        return dp[n][n];
    }
};
```