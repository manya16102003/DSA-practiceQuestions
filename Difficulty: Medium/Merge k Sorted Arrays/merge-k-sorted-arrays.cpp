//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
class info
{
    public:
    int value;
    int col;
    int row;
    info(int val , int r , int c)
    {
        value=val;
        row=r;
        col=c;
    }
};
class compare
{
    public:
    bool operator()(info * a , info*b)
    {
        return a->value>b->value;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    
    void mergeKsorted(vector<vector<int>> &arr, int &k , vector<int>&ans)
    {
        priority_queue<info*,vector<info*>,compare>minheap;
        for(int i=0;i<k;i++)
        {
            auto temp=new info(arr[i][0] , i , 0);
            minheap.push(temp);
        }
        while(!minheap.empty())
        {
            auto temp=minheap.top();
            int topelement=temp->value;
            int row=temp->row;
            int col=temp->col;
            minheap.pop();
            ans.push_back(topelement);
            if(col+1<k)
            {
                auto newelement=new info(arr[row][col+1] , row , col+1);
                minheap.push(newelement);
            }
            
        }
        
    }
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>ans;
        mergeKsorted(arr , K , ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends