//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zerohead=new Node(-1);
        Node* zerotail=zerohead;
        
        Node* onehead=new Node(-1);
        Node* onetail=onehead;
        
        Node* secondhead=new Node(-1);
        Node* secondtail=secondhead;
        
        Node* curr=head;
        while(curr!=NULL)
        {
            if(curr->data==0)
            {
                zerotail->next=curr;
                zerotail=zerotail->next;
            }
           else if(curr->data==1)
            {
                onetail->next=curr;
                onetail=onetail->next;
            }
            else if(curr->data==2)
            {
                secondtail->next=curr;
                secondtail=secondtail->next;
            }
            curr=curr->next;
        }
        zerotail->next=(onehead->next)?(onehead->next):(secondhead->next);
        onetail->next=secondhead->next;
        secondtail->next=NULL;
        
        Node* newnode=zerohead->next;
        
        delete(zerohead);
        delete(onehead);
        delete(secondhead);
        
        return newnode;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends