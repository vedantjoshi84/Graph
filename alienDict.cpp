//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// ***************************************************************
// Important not possible conditions: 
// 1. If larger string appears before shorter eg. abcd and abc 
// 2. If there is a cyclic dependency eg. abc bat ade 
// ***************************************************************

class Solution{
    private: 
    void topoSort(vector<int> adj[], int K, vector<int> &topo) {
        queue<int> q;
        vector<int> indegree(K, 0);
        for(int i=0;i<K;i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        for(int i=0;i<K;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
    }
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        
        for(int i=0;i<N-1;i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int n = min(s1.length(), s2.length());
            for(int j=0;j<n;j++) {
                if(s1[j]!=s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    // Very important to break on first char mismatch
                    break;
                }
            }
        }
        vector<int> topo;
        topoSort(adj, K, topo);
        string str="";
        for(auto it: topo) {
            // Imp char conversion
            str = str + char(it + 'a');
        }
        return str;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends