class Solution {
public:
    bool dfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        if(x<0 || x>= m || y<0 || y>= n){
            return false;
        }

        if(grid[x][y] == 1 || vis[x][y]){
            return true;
        }

        vis[x][y] = true;
        bool isClosed = true;
        vector<int> nr {0,1,0,-1};
        vector<int> nc {-1,0,1,0};

        for(int i = 0; i<4; i++){
            int r = x + nr[i];
            int c = y + nc[i];
            if(!dfs(r,c,m,n,grid,vis)){
                isClosed = false;
            }
        }
        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(m,vector<bool>(n));
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j]==0 && !vis[i][j] && dfs(i,j,m,n,grid,vis)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};