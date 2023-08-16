class Solution {
private:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        int row[4] = {0, -1, 0, 1};
        int col[4] = {-1, 0, 1, 0};
        while(!q.empty()) {
            int nr = q.front().first;
            int nc = q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int delr = nr + row[i];
                int delc = nc + col[i];

                if(delr>=0 && delr<m && delc>=0 && delc<n && 
                   !vis[delr][delc] && grid[delr][delc]==1) {
                       vis[delr][delc] = 1;
                       q.push({delr, delc});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if( (i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1) {
                    bfs(grid, vis, i, j);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    cnt++;
                }
            }
        }
        return cnt; 
    }
};
