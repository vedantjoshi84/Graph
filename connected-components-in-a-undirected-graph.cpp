#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> &visited, vector<int> adj[]) {
	visited[i] = 1;
	for(auto it: adj[i]) {
		if(!visited[it]) {
			dfs(it, visited, adj);
		}
	}
}

int main() {
	int n, e;
	cin>>n>>e;
	vector<int> adj[n+1];
	for(int i=0;i<e;i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	} 
	int comp = 0;
	vector<int> visited(n+1, 0);
	for(int i=1;i<=n;i++) {
		if(!visited[i]) {
			comp++;
			dfs(i, visited, adj);
		}
	}
	cout<<comp;
}

