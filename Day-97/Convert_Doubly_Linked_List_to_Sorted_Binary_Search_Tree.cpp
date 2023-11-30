#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data =data;
        this->left = NULL;
        this->right = NULL;
    }
};



Node* buildBinerySearchTree(Node*root,int data){
    // Empty tree
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    // Not empty tree
    if(root->data > data){
        // insert into left
        root->left = buildBinerySearchTree(root->left,data);
    }
    else{
        // insert into right
        root->right = buildBinerySearchTree(root->right,data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root  = buildBinerySearchTree(root,data);
        cin>>data;
    }

}

//bst to sorted linked list
void convertIntoSortedDLL(Node*root,Node* &head){
    if(root == NULL){
        return;
    }
    //right subtree into linked list
    convertIntoSortedDLL(root->right,head);

    //attach root node
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    //update head
    head = root;
    //left subtree linked list
    convertIntoSortedDLL(root->left,head);

}

void printDDL(Node*&head){
    Node*temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}



//Dubly linked list to binery search tree
Node* DLLToBST(Node* &head,int n){
    if(n <=0  ){
        return NULL;
    }

    Node* leftSubTree = DLLToBST(head,n/2);

    Node*root = head;
    head->left = leftSubTree;

    head = head->right;

    root->right = DLLToBST(head,n-n/2-1);

    return root;
}



//level order traversal
// To print the tree level wise
void levelOrderTraversal(Node *root)
{
    // Empty tree
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // Push the root in queue
    q.push(root);
    q.push(NULL);
    // Run the loop until queue becomes empty
    while (!q.empty())
    {
        // Fetch front node and then pop
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // go to the next line
            cout << endl;
            // Marking for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // left child exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // right child exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}


int main(){
    Node*root = NULL;
    cout<<"Enter the data for Node"<<endl;
    takeInput(root);
    //input 10 5 15 11 20 9 8 3 4 -1

    Node* head = NULL;
    convertIntoSortedDLL(root,head);

    cout<<"printing Doubly linked list:"<<endl;
    printDDL(head);
    cout<<endl;
    cout<<endl;

    Node*newroot = NULL;
    newroot=  DLLToBST(head,9);
    
    cout<<"printing bst by level order traversal:"<<endl<<endl;
    levelOrderTraversal(newroot);
    
    return 0;
}


