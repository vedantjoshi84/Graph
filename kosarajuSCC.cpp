//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int node, vector<vector<int>>& adj, stack<int> &st, vector<int> &vis) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, st, vis);
            }
        }
        st.push(node);
    }
    void dfsR(int node, vector<int> &vis, vector<vector<int>> &adjR) {
        vis[node] = 1;
        for(auto it: adjR[node]) {
            if(!vis[it]) {
                dfsR(it, vis, adjR);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                dfs(i, adj, st, vis);
            }
        }

        // Imp to mention the fix size of adjR here, to use indexing as on line 43.
        vector<vector<int>> adjR(V);
        for(int i=0;i<V;i++) {
            vis[i] = 0;
            for(auto it: adj[i]) {
                adjR[it].push_back(i);
            }
        }

        int scc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                scc++;
                dfsR(node, vis, adjR);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends