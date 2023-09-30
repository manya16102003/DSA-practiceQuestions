//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long countpair(int n, int k, int target,vector<vector<long long>>&dp)
{
    if(n<0) return 0;
    if(n==0 &&target==0) return 1;
    if(n==0 &&target!=0) return 0;
    if(target==0&& n!=0) return 0;
    if(dp[n][target]!=-1) return dp[n][target];
    long long ans=0;
    
    for(int i=1;i<=k;i++)
    {
        long long recans=0;
        if(target-i>=0)
         recans=countpair(n-1,k,target-i,dp);
         ans=(ans+recans);
         dp[n][target]=ans;
    }
    return dp[n][target];
}
    long long noOfWays(int k , int n , int target) {
        // code here
        vector<vector<long long>>dp(n+1,vector<long long>(target+1,-1));
        return countpair(n,k,target,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends