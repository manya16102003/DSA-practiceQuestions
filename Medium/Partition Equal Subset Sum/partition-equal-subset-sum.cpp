//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool findsubset(int N,int nums[],int target,int index, vector<vector<int>>&dp)
{
    int n=N-1;
    if(index>n) return 0;
    if(target==0) return 1;
    if(target<=0) return 0;
    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }
    bool include=findsubset(N,nums,target-nums[index],index+1,dp);
    bool exclude=findsubset(N,nums,target,index+1,dp);
    dp[index][target]=(include||exclude);
     return dp[index][target];
}
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
          int target=sum/2;
        vector<vector<int>>dp(N,vector<int>(target+1,-1));
        if(sum&1) return 0;
      
        int index=0;
        return findsubset(N,arr,target,index,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends