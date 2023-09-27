//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int n,int k,vector<long long>&dp)
    {
      long long mod=1000000007;
        if(n==1) return k;
        if(n==2) return k*k;
        if(dp[n]!=-1) return dp[n];
        long long a=solve(n-1,k,dp)*(k-1);
        long long b=solve(n-2,k,dp)*(k-1);
        dp[n]=(a+b)%mod;
        return dp[n];
    }
    long long countWays(int n, int k){
        // code here
        vector<long long>dp(n+1,-1);
        return solve(n,k,dp);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends