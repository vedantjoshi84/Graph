class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m , vector<int> (n, 0));
        vector<vector<int>> vis(m , vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 0) {
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int row[4] = {0, -1, 0, 1};
        int col[4] = {-1, 0, 1, 0};
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            dis[r][c] = d;

            for(int i=0;i<4;i++) {
                int delr = r + row[i];
                int delc = c + col[i];

                if(delr>=0 && delr<m && delc>=0 && delc<n && 
                    vis[delr][delc]==0 && mat[delr][delc]==1) {
                        vis[delr][delc] = 1;
                        q.push({{delr, delc}, d+1});
                }
            }
        }
        return dis;
    }
};
