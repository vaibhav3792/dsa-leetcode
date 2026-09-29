class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m+n%2==0) return false;

        vector<vector<vector<bool>>> dp(m,vector<vector<bool>>(n,vector<bool>(m+n,false)));

        if(grid[0][0] == ')') return false;

        dp[0][0][1] = true;

        for(int i = 0; i<m;i++){
            for(int j = 0; j<n;j++){
                if(i==0 && j==0) continue;

                for(int b = 0; b<=m+n;b++){
                    if(b<0) continue;

                    int remaining = (m-1-i) + (n-1-j);

                    if(b>remaining) continue;

                    if(grid[i][j]=='('){
                        if(b>=1){
                            if(i>0 && dp[i-1][j][b-1] == true){
                                dp[i][j][b] = true;
                            }
                            if(j>0 && dp[i][j-1][b-1] == true){
                                dp[i][j][b] = true;
                            }
                        }
                    } else{
                        if (i > 0 && dp[i - 1][j][b + 1])
                            dp[i][j][b] = true;

                        if (j > 0 && dp[i][j - 1][b + 1])
                            dp[i][j][b] = true;
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};