class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid, int r0, int c0, vector<pair<int, int>> &v) {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        v.push_back({row - r0, col - c0});
        
        int delr[4] = {0, 1, 0, -1};
        int delc[4] = {1, 0, -1, 0};
        
        for(int i=0;i<4;i++) {
            int r = row + delr[i];
            int c = col + delc[i];
            
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]==1) {
                dfs(r, c, vis, grid, r0, c0, v);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        set< vector<pair<int, int>> > s;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    vector<pair<int, int>> v;
                    dfs(i, j, vis, grid, i, j, v);
                    s.insert(v);
                }
            }
        }
        
        return s.size();
    }
};
