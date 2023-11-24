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




int main()
{
    Node *root = builder();

    morrisTraversal(root);

    return 0;
}