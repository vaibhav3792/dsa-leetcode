- To make a string a palindrome, we can either delete the elements that stop it from becoming a palindrome or just add those elements again to make pairs and get the result as a palindrome
- Basically minimum number of insertions in a string to make it a palindrome is equal to the minimum number of deletions.

## Code
```cpp
class Solution {
  public:
    int minInsertions(string &s) {
        // code here
        int n = s.length();
        string a = s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=n;j++){
                if(a[i-1]==s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return n - dp[n][n];
    }
};
```