## Identifying DP Qs
1) Choice will be given like take or not take
2) Optimize
    - Find min, max, longest, shortest, etc

## Input and Output format
- i/p : 2 strings
- o/p : int

- Matches with current Q so think of using LCS

## LCS
- To convert heap into pea, we will delete h and p while inserting p at the front
- ea will remain untouched. It is the LCS for the two strings
- '#' of Insertion -> b.length() - LCS
- Deletion -> a.length() - LCS

## Code
```cpp
class Solution {

  public:
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
        return n + m - 2*dp[n][m];
    }
};
```