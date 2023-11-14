#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data= data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* BuildTree(){
    int data;
    cout << "enter the element to insert:";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    cout << "Enter the data for left part of " << data << " Node" << endl;
    root->left = BuildTree();
    cout << "Enter the data for right part of " << data << " Node" << endl;
    root->right = BuildTree();

    return root;
}



bool kthAncestor(Node* root,int &k,int p){
    if(root == NULL){
        return false;
    }

    if( root->data == p){
        return true;
    }

    bool leftAns = kthAncestor(root->left,k,p);
    bool rightAns = kthAncestor(root->right,k,p);

    if(leftAns == true || rightAns == true){
        k--;
    }
    if(k == 0){
        cout<<"kth Ancestor is:"<<root->data;
        k = -1;
    }

    return leftAns || rightAns;

}


int main()
{
    Node* root = BuildTree();
    int k = 1;
    int p = 4;
    bool ans1 = kthAncestor(root,k,p);

    

    return 0;
}