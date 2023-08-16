class Solution {

private:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int r, int c) {
        int row[4] = {0, -1, 0, 1};
        int col[4] = {-1, 0, 1, 0};
        int m = board.size();
        int n = board[0].size();
        vis[r][c] = 1;
        for(int i=0;i<4;i++) {
            int delr = row[i] + r;
            int delc = col[i] + c;
            if(delr>=0 && delr<m && delc>=0 && delc<n && 
               !vis[delr][delc] && board[delr][delc]=='O') {
                   dfs(board, vis, delr, delc);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if( (i==0 || j==0 || i==m-1 || j==n-1) && board[i][j]=='O' ) {
                    dfs(board, vis, i, j);
                }
            }
        }
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(vis[i][j]==0 && board[i][j]=='O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
