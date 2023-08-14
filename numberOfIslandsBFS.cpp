class Solution {

private: 
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int delrow=-1; delrow<=1; delrow++) {
                for(int delcol=-1; delcol<=1; delcol++) {
                    int nrow = r + delrow;
                    int ncol = c + delcol;

                    // This is to skip diagonal connections
                    if(delrow!=0 && delcol!=0) {
                        continue;
                    }

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                       grid[nrow][ncol]=='1' && !visited[nrow][ncol]) {
                           visited[nrow][ncol] = 1;
                           q.push({nrow, ncol});
                    }
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
                    bfs(row, col, visited, grid);
                }
            }
        }
        return cnt;
    }
};
