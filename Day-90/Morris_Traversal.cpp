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



//MorrisTraversal for inorder
void morrisTraversal(Node* root){
    vector<int> ans;
    Node* curr= root;
    while(curr){
        //left node is null, then visit it and go right
        if(curr->left == nullptr){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        //left node is not null
        else{
            //find inorder predicessor
            Node* pred = curr->left;
            while(pred->right != curr && pred->right){
                pred = pred->right;
            }

            //if right node is null, then go left after establessing link form pred to curr
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                //left is already visited, go right after visiting curr node, while removing the link
                pred->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    for(auto i:ans){
        cout<<i<<" ";
    }
}


// Preorder traversal without recursion and without stack  
void morrisTraversalPreorder(Node* root)  
{  

    while (root)  
    {  
        // If left child is null, print the current node data. Move to  
        // right child.  
        if (root->left == NULL)  
        {  
            cout<<root->data<<" ";  
            root = root->right;  
        }  
        else
        {  
            // Find inorder predecessor  
            Node* current = root->left;  
            while (current->right && current->right != root)  
                current = current->right;  
  
            // If the right child of inorder predecessor already points to  
            // this node  
            if (current->right == root)  
            {  
                current->right = NULL;  
                root = root->right;  
            }  
  
            // If right child doesn't point to this node, then print this  
            // node and make right child point to this node  
            else
            {  
                cout<<root->data<<" ";  
                current->right = root;  
                root = root->left;  
            }  
        }  
    }  
}  

// Postorder traversal
// Without recursion and without stack
vector<int> postorderTraversal(Node* root)
{
    vector<int> res;
    Node* current = root;
 
    while (current != NULL) {
        // If right child is null,
        // put the current node data
        // in res. Move to left child.
        if (current->right == NULL) {
            res.push_back(current->data);
            current = current->left;
        }
        else {
            Node* predecessor = current->right;
            while (predecessor->left != NULL
                   && predecessor->left != current) {
                predecessor = predecessor->left;
            }
            // If left child doesn't point
            // to this node, then put in res
            // this node and make left
            // child point to this node
            if (predecessor->left == NULL) {
                res.push_back(current->data);
                predecessor->left = current;
                current = current->right;
            }
            // If the left child of inorder predecessor
            // already points to this node
            else {
                predecessor->left = NULL;
                current = current->left;
            }
        }
    }
    // reverse the res
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    Node *root = builder();

    morrisTraversal(root);

    return 0;
}