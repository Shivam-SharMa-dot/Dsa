// gfg good question to 
#include <bits/stdc++.h>
using namespace std;
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
        Node*zerosdummy=new Node(-1); 
        Node*temp0= zerosdummy;
        
        Node*onesdummy=new Node(-1);
        Node* temp1=onesdummy;
        
        Node*twosdummy=new Node(-1);
        Node*temp2=twosdummy;
        
        Node* temp = head;
        while(temp !=NULL){
            if(temp->data == 0){
                temp0->next=temp;
                temp0=temp;  // move zeros forward
            }
           else if(temp->data == 1){
                temp1->next=temp;
                temp1=temp;  // move onespointer  forward
            }
           else{
                temp2->next=temp;
                temp2=temp;  // move zeros forward
           }
            temp= temp->next;
        }
        // now connect the zeros and ones and twos pointer 
        // we have to check if ones or twos are not peresent in whole array
        
        if(onesdummy->next != NULL){  // if one's dumy is present then will connect 
                                       //zerodummy next to one dummy's next or
                                       //else directly to  twos dummy next directly
             temp0->next=onesdummy->next;
        }
        else{   // if one's not present direct point to two's dummy   02020202
            temp0->next=twosdummy->next;
        }
        
        // if zeros not present 112221211
        temp1->next=twosdummy->next;
        temp2->next=NULL;
        
        delete zerosdummy;
        delete onesdummy;
        delete twosdummy;
        
        return zerosdummy->next;
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