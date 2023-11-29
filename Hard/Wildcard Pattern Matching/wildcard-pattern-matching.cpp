//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
  int ismatching(string &s,string &p,int si, int pi , vector<vector<int>>&dp)
    {
        if(si<0&&pi<0) return true;
        if(si>=0&&pi<0) return false;
        if(si<0&&pi>=0)
        {
            for(int i=0;i<=pi;i++)
            {
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(dp[si][pi] !=-1) return dp[si][pi];
        if(s[si]==p[pi]||'?'==p[pi]) return dp[si][pi]= ismatching(s,p,si-1,pi-1,dp);
        else if(p[pi]=='*')
        {
            return dp[si][pi]=(ismatching(s,p,si,pi-1,dp)||ismatching(s,p,si-1,pi,dp));
        }
        else return false;
    }
    int wildCard(string pattern,string str)
    {
        int si=str.size();
        int pi=pattern.size();
        vector<vector<int>>dp(si,vector<int>(pi,-1));
        return ismatching(str,pattern,si-1,pi-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends