// Problem Statement: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V], dfsVis[V];
        memset(vis, 0, sizeof(vis));
        memset(dfsVis, 0, sizeof(dfsVis));

        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(checkCycle(i, adj, vis, dfsVis)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]) {
        vis[node] = 1;
        dfsVis[node] = 1;

        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(checkCycle(it, adj, vis, dfsVis)) {
                    return true;
                }
            }
            else if(dfsVis[it]) {
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends