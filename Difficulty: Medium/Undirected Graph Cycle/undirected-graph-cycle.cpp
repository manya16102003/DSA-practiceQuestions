//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detection(int src , vector<int> adj[] ,unordered_map<int , bool>&visisted )
    {
        
        queue<int>q;
        unordered_map<int , int>parent;
        q.push(src);
        visisted[src]=true;
        parent[src]=-1;
        while(!q.empty())
        {
            int frontnode=q.front();
            q.pop();
            
            for(auto nbr:adj[frontnode])
            {
                if(!visisted[nbr])
                {
                    q.push(nbr);
                    visisted[nbr]=true;
                    parent[nbr]=frontnode;
                }
                else
                {
                    //visisted
                    if(nbr!=parent[frontnode])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here'
        unordered_map<int , bool>visisted;
        bool ans=false;
        for(int i=0;i<V;i++)
        {
            if(!visisted[i])
            ans=detection(i,adj , visisted );
            
            if(ans==true) 
            break;
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