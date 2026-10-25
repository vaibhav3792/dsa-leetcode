
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        vector<vector<bool>> vis(m, vector<bool>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !vis[i][j] &&
                    bfs(i, j, m, n, grid, vis)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }

    bool bfs(int x, int y, int m, int n,
             vector<vector<int>>& grid,
             vector<vector<bool>>& vis) {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = true;

        bool isClosed = true;
        vector<int> drx{0, 1, 0, -1};
        vector<int> dry{-1, 0, 1, 0};

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = x + drx[i];
                int c = y + dry[i];

                if (r < 0 || r >= m || c < 0 || c >= n) {
                    isClosed = false;
                } 
                else if (grid[r][c] == 0 && !vis[r][c]) {
                    q.push({r, c});
                    vis[r][c] = true;
                }
            }
        }

        return isClosed;
    }
};
