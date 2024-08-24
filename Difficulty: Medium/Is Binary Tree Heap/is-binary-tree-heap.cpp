//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  int countnode(struct Node* root)
  {
      if(!root) return 0;
      int l=countnode(root->left);
      int r=countnode(root->right);
      return l+r+1;
  }
  bool isCBT(struct Node* tree,int i,int&n)
  {
      if(!tree) return true;
      if(i>n) return false;
      return isCBT(tree->left,2*i,n)&&isCBT(tree->right,2*i+1,n);
  }
  bool ismaxorder(struct Node* root)
  {
      if(!root) return true;
      int l=ismaxorder(root->left);
      int r=ismaxorder(root->right);
      bool ans=false;
      if(!root->left&&!root->right) return true;
      if(root->left&& !root->right)
      {
          ans=root->data>root->left->data;
      }
      else
      {
          ans=root->data>root->left->data&&root->data>root->right->data;
      }
      return l&&r&&ans;
      
  }
    bool isHeap(struct Node* tree) {
        // code here
        int n=countnode(tree);
        int i=1;
        return isCBT(tree,i,n)&&ismaxorder(tree);
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends