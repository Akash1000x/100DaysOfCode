#include <iostream>
#include <queue>
using namespace std;

// creating a node
class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *builder()
{

    int data;
    cout << "enter the element to insert:";
    cin >> data;

    // -1 data indicates that we have the leaf node (Base Case)
    if (data == -1)
    {
        return NULL;
    }
    // Create the root node and hence solved 1 case
    Node *root = new Node(data);

    // Recursion will handle
    cout << "Enter the data for left part of " << data << " Node" << endl;
    root->left = builder();

    cout << "Enter the data for right part of " << data << " Node" << endl;
    root->right = builder();

    return root;
}

//postOrderTraversal approach(LRN -  left right node)
void postOrderTraversal(Node *root)
{
    //base case
    if(root == NULL ){
        return;
    }


    //LRN

    //left
    postOrderTraversal(root->left);

    //right
    postOrderTraversal(root->right);

    cout<<root->data<<" ";
 
}

int main()
{
    Node *root = builder();

    postOrderTraversal(root);

    return 0;
}