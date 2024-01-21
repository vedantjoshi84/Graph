class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<int> vis(n, 0);
        int timer = 0;
        vector<vector<int>> bridges;

        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(i, -1, vis, low, tin, bridges, timer, adj);
            }
        }
        return bridges;
    }

    void dfs(int node, int parent, vector<int> &vis, vector<int> &low, vector<int> &tin, vector<vector<int>> &bridges, int timer, vector<int> adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it: adj[node]) {
            if(it == parent) {
                continue;
            }

            if(!vis[it]) {
                dfs(it, node, vis, low, tin, bridges, timer, adj);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
};