//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool issafe(int i, int j, int row, int col,vector<vector<int>> &m,vector<vector<bool>>&visited)
    {
        if((i>=0&&i<row)&&(j>=0&&j<col)&&(m[i][j]==1)&&(visited[i][j]==false))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void solvemaze(vector<vector<int>> &m,int rows,int col,int i,int j,vector<vector<bool>>&visited,
    vector<string>&path,string output)
    {
        if(i==rows-1&&j==col-1)
        {
            path.push_back(output);
            return;
        }
        if(issafe(i+1,j,rows,col,m,visited))
        {visited[i+1][j]=true;
        solvemaze(m, rows, col,i+1,j,visited,path,output+'D');
         visited[i+1][j]=false;}
         
         
          if(issafe(i,j-1,rows,col,m,visited))
        {visited[i][j-1]=true;
        solvemaze(m, rows, col,i,j-1,visited,path,output+'L');
         visited[i][j-1]=false;}
         
          if(issafe(i,j+1,rows,col,m,visited))
        {visited[i][j+1]=true;
        solvemaze(m, rows, col,i,j+1,visited,path,output+'R');
         visited[i][j+1]=false;}
         
          if(issafe(i-1,j,rows,col,m,visited))
        {visited[i-1][j]=true;
        solvemaze(m, rows, col,i-1,j,visited,path,output+'U');
         visited[i-1][j]=false;
            
        }
    }
    
    
    vector<string> findPath(vector<vector<int>>&mat) {
        // Your code goes here
       
         int rows=mat.size();
         int col=mat[0].size();
         vector<string>path;
         string output="";
         
        vector<vector<bool>>visited(rows,vector<bool>(col,false));
        
        
        if(mat[0][0]==0)
        {
            return path;
        }
        visited[0][0]=true;
        solvemaze(mat, rows,col,0,0,visited,path,output);
       
        
       
         return path;
    }
};

    



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends