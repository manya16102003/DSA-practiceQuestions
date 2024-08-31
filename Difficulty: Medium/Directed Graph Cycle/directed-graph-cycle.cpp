//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool detection (int src , unordered_map<int , bool>&visisted ,unordered_map<int , bool >&dfsvisisted,vector<int> adj[] )
    {
        visisted[src]=true;
        dfsvisisted[src]=true;
        for(auto nbr:adj[src])
        {
            if(!visisted[nbr])
            {
                bool checkans=detection(nbr , visisted , dfsvisisted , adj);
                if(checkans==true) return true;
            }
           else if(visisted[nbr] && dfsvisisted[nbr])
            {
                return true;
            }
        }
        dfsvisisted[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        unordered_map<int , bool>visisted;
        unordered_map<int , bool >dfsvisisted;
        bool ans=false;
        for(int i=0;i<V;i++)
        {
            if(!visisted[i])
            {
                ans=detection(i , visisted , dfsvisisted , adj);
            }
            if(ans==true) break;
        }
        return ans;
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