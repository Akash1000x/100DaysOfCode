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

int maxValue(Node* root){
   
    Node *temp = root;
    if (temp == NULL)
        return -1;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

int MiniValue(Node* root){
    
    Node *temp = root;
    if (temp == NULL)
        return -1;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
    
}

int main(){
    Node*root = NULL;
    cout<<"Enter the data for Node"<<endl;
    takeInput(root);

    // example input 10 5 20 4 6 70 80 50 15 -1
    cout<<"Maximum value is:"<<maxValue(root)<<endl;
    cout<<"Minimum value is:"<<MiniValue(root)<<endl;
    return 0;
}


