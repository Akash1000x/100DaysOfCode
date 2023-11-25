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

bool findNode(Node*root,int target){
    if(root==NULL){
        return false;
    }

    if(root->data == target){
        return true;
    }

    if(root->data > target){
        //left
        return findNode(root->left,target);
    }
    else{
        //right
        return findNode(root->right,target);
    }
}

int main(){
    Node*root = NULL;
    cout<<"Enter the data for Node"<<endl;
    takeInput(root);

    //check a value presnt or not in BST 
    int target = 50; //for input 10 5 20 4 6 70 80 50 15 -1
    if( findNode(root,target) ){
        cout<<target<<" is present in BST";
    }
    else{
        cout<<target<<" is not presnt in BST";
    }
    
    return 0;
}


