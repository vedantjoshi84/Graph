//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;
        
        dist[source.first][source.second] = 0; 
        q.push( {0, {source.first, source.second}} );
        
        int r[] = {0, -1, 0, 1};
        int c[] = {-1, 0, 1, 0};
        while(!q.empty()) {
            int dis = q.front().first;
            pair<int, int> p = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++) {
                int delr = r[i] + p.first;
                int delc = c[i] + p.second;
                
                if(delr>=0 && delr<n && delc>=0 && delc<m && grid[delr][delc]==1 && dis + 1 < dist[delr][delc]) {
                    dist[delr][delc] = dis + 1;
                    if(delr == destination.first && delc == destination.second) {
                        return dist[delr][delc];
                    }
                    q.push( {dist[delr][delc], {delr, delc}} );
                }
            }
        }
        
        // Imp edge case to handle  
        if(source.first==destination.first && source.second==destination.second) 
            return 0;
            
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
