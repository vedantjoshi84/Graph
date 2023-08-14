class Solution {
    
private: 
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for(int delrow=-1; delrow<=1; delrow++) {
            for(int delcol=-1; delcol<=1; delcol++) {
                int nrow = row + delrow;
                int ncol = col + delcol;

                // This is to skip diagonal connections
                if(delrow!=0 && delcol!=0) {
                    continue;
                }

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    grid[nrow][ncol]=='1' && !visited[nrow][ncol]) {
                        dfs(nrow, ncol, visited, grid);
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int cnt = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                if(!visited[row][col] && grid[row][col]=='1') {
                    cnt++;
                    dfs(row, col, visited, grid);
                }
            }
        }
        return cnt;
    }
};
