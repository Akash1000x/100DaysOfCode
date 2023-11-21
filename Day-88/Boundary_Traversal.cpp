#include <iostream>
#include <queue>
#include<vector>
#include<map>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node *buildTree(){
    int data;
    cout<<"Enter the element to insert:";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);

   // Recursion will handle
    cout << "Enter the data for left part of " << data << " Node" << endl;
    root->left = buildTree();

    cout << "Enter the data for right part of " << data << " Node" << endl;
    root->right = buildTree();

    return root;
}


void printLeftNodes(Node* root){
    // Base case
    if(root == NULL){
        return;
    }
    // Leaf node (we have to stop)
    if(root->left == NULL && root->right == NULL){
        return;
    }
    cout<<root->data<<" ";

    if(root->left)
        printLeftNodes(root->left);
    // if left nodes does not exist
    else
        printLeftNodes(root->right);
}


void printLeafNodes(Node* root){
    if(root == NULL){
        return;
    }
    
    printLeafNodes(root->left);

    // leaf node found
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }

    printLeafNodes(root->right);
}


void printRightNodes(Node* root){
    // Base case
    if(root == NULL){
        return;
    }
    // Leaf node (we have to stop)
    if(root->left == NULL && root->right == NULL){
        return;
    }
    // Right call first
    if(root->right)
        printRightNodes(root->right);
    // Left call 
    else
        printRightNodes(root->left);
        
    cout<<root->data<<" ";
}


// Boundary Traversal
void boundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // First print the root node so that duplicacy is not there
    cout<<root->data<<" ";
    // Print left nodes
    printLeftNodes(root->left);
    // Print leaf nodes

    if(root->left  || root->right){
        printLeafNodes(root);

    }
    // Print right nodes in reverse order
    printRightNodes(root->right);
}

// 20 30 -1 -1 50 70 90 -1 -1 80 -1 -1 60 -1 -1 
int main()
{
    Node* root = buildTree();
    boundaryTraversal(root);
    return 0;
}