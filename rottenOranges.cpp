class Solution {
public: 
    int maxt = 0;

private:
    void bfs(vector<vector<int>>& grid, queue <pair<pair<int, int>, int>> &q) {
        int m = grid.size();
        int n = grid[0].size();

        int rows[] = {0, -1, 0, 1};
        int cols[] = {-1, 0, 1, 0};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            maxt = max(maxt, t);
            q.pop();

            for(int z=0;z<4;z++) {
                int delrow = row + rows[z];
                int delcol = col + cols[z];

                if(delrow>=0 && delrow<m && delcol>=0 && delcol<n && grid[delrow][delcol]==1) {
                    grid[delrow][delcol] = 2;
                    q.push( { {delrow, delcol}, t+1} );
                }
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Imp. See the way of declaration
        queue < pair < pair<int, int>, int> > q;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2) {
                    // Imp step. To push all the rotten oranges simultaneously
                    q.push({{i, j}, 0});
                }
            }
        }

        bfs(grid, q);

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }

        return maxt; 
    }
};
