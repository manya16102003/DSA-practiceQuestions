//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
   void traversal(vector<int> adj[] , int src ,vector<int>&ans , unordered_map<int , bool>&visited)
    {
        visited[src]=true;
        ans.push_back(src);
        for(auto neighbour:adj[src])
        {
            if(!visited[neighbour])
            {
                traversal(adj , neighbour , ans , visited);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       int src=0;
       unordered_map<int , bool>visited;
       vector<int>ans;
       traversal(adj , src , ans , visited);
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends