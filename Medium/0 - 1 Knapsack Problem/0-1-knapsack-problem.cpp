//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, int wt[], int val[], int index,vector<vector<int>>&dp)
    {
        if(index==0)
        {
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        
        if(dp[index][W]!=-1)
        {
            return dp[index][W];
        }
        int include=0;
        if(W>=wt[index])
        {
        include=val[index]+solve(W-wt[index],wt,val,index-1,dp);
        }
        int exclude=0+solve(W,wt,val,index-1,dp);
        dp[index][W]=max(include,exclude);
        return dp[index][W];
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return solve(W,wt,val,n-1,dp);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends