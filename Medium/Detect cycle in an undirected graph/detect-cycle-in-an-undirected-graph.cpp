//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detection (int src , unordered_map<int, bool>&visited,vector<int> adj[] )
    {
        queue<int>q;
        
        unordered_map<int, int> parent;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        while(!q.empty())
        {
            int frontnode=q.front();
            q.pop();
            for(auto nbr:adj[frontnode])
            {
                if(!visited[nbr])
                {
                    visited[nbr]=true;
                    q.push(nbr);
                    parent[nbr]=frontnode;
                }
                else
                {
                    if(nbr!=parent[frontnode]) return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here

        
        bool ans=false;
        unordered_map<int, bool> visited;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                ans=detection(i,visited,adj);
               if(ans==true) break;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends