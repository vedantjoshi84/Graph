//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class DisjointSet {
    vector<int> rank, size, parent;
    public:
        DisjointSet(int v) {
            rank.resize(v+1, 0);
            size.resize(v+1);
            parent.resize(v+1);
            for(int i=0;i<=v;i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUParent(int node) {
            if(node == parent[node]) {
                return node;
            }
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int upu = findUParent(u);
            int upv = findUParent(v);

            if(upu == upv) {
                return;
            }
            if(rank[upu] < rank[upv]) {
                parent[upu] = upv;
            }
            else if(rank[upv] < rank[upu]) {
                parent[upv] = upu;
            }
            else {
                parent[upv] = upu;
                rank[upu]++;
            }
        }

        void unionBySize(int u, int v) {
            int upu = findUParent(u);
            int upv = findUParent(v);

            if(upu == upv) {
                return;
            }
            if(size[upu] < size[upv]) {
                parent[upu] = upv;
                size[upv] += size[upu];
            }
            else {
                parent[upv] = upu;
                size[upu] += size[upv];
            }
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0;i<V;i++) {
            for(auto it: adj[i]) {
                int node = i;
                int adjNode = it[0];
                int edW = it[1];
                edges.push_back({edW, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mst = 0;
        for(auto it: edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            // Here we can store (u, v) if asked to store MST

            if(ds.findUParent(u) != ds.findUParent(v)) {
                mst += wt;
                ds.unionBySize(u, v);
            }
        }
        return mst;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends