//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>>ans;
        queue<pair<vector<string>,int>>q;
        vector<string>toberemoved;
        q.push({{beginWord} , 1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        int prevlevel=-1;
        
        while(!q.empty())
        {
            auto fnode=q.front();
            q.pop();
            auto currseq=fnode.first;
            auto currword=currseq[currseq.size()-1];
            auto currcount=fnode.second;
            
            if(currcount!=prevlevel)
            {
                for(auto s :toberemoved)
                {
                    st.erase(s);
                }
                toberemoved.clear();
                prevlevel=currcount;
            }
            if(currword==endWord) ans.push_back(currseq);
            for(int i=0;i<currword.size();i++)
            {
                char originalchar=currword[i];
                for(char ch='a';ch<='z';ch++)
                {
                    currword[i]=ch;
                    if(st.find(currword)!=st.end())
                    {
                        auto temp =currseq;
                        temp.push_back(currword);
                        q.push({temp , currcount+1});
                        toberemoved.push_back(currword);
                    }
                }
                currword[i]=originalchar;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends