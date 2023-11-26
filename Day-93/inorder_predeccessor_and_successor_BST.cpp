#include<iostream>
#include<queue>
#include<limits.h>
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



Node* buildBinerySearch(Node*root,int data){
    // Empty tree
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    // Not empty tree
    if(root->data > data){
        // insert into left
        root->left = buildBinerySearch(root->left,data);
    }
    else{
        // insert into right
        root->right = buildBinerySearch(root->right,data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root  = buildBinerySearch(root,data);
        cin>>data;
    }

}

Node* findNode(Node*root,int target){
    if(root==NULL){
        return nullptr;
    }

    if(root->data == target){
        return root;
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


//its find only when the sub tree is availabel of target value 
void findInOrderPredeccessor(Node*root,int value){
    
    Node* temp = findNode(root,value);
    
    
    int inOrderPredeccessor = maxValue(temp->left);
    cout<<"inOrderPredeccessor is: "<<inOrderPredeccessor<<endl;

}


//its find only when the sub tree is availabel of target value 
void findInOrderSuccessor(Node*root,int value){
    Node* temp = findNode(root,value);
    
    
    int inOrderSuccessor = MiniValue(temp->right);
    cout<<"inOrderSuccessoris: "<<inOrderSuccessor<<endl;

}

int main(){
    Node*root = NULL;
    cout<<"Enter the data for Node"<<endl;
    takeInput(root);
    findInOrderPredeccessor(root,10);
    findInOrderSuccessor(root,10);

}


