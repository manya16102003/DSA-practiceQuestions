//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool cycle(vector<int> adj[],int src,unordered_map<int,bool>&visited,
                unordered_map<int,bool>&dfsvisited,int safenode[]){
                    visited[src]=true;
                    dfsvisited[src]=true;
                    safenode[src]=0;
                    for(auto nbr:adj[src]){
                        if(!visited[nbr]){
                            bool nextans=cycle(adj,nbr,visited,dfsvisited,safenode);
                            if(nextans==true)
                                return true;
                        }
                        if(visited[nbr]==true && dfsvisited[nbr]==true)
                            return true;
                    }
                    dfsvisited[src]=false;
                    safenode[src]=1;
                    return false;
                }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_map<int,bool> visited,dfsvisited;
        int safenode[V]={0};
        for(int i=0;i<V;i++){
            if(!visited[i])
                cycle(adj,i,visited,dfsvisited,safenode);
        }
        for(int i=0;i<V;i++){
            if(safenode[i]) ans.push_back(i);
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends