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

void printDDL(Node*head){
    Node*temp = head;
    while(temp->data){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}

int main(){
    Node*root = NULL;
    cout<<"Enter the data for Node"<<endl;
    takeInput(root);

    Node* head = NULL;
    convertIntoSortedDLL(root,head);

    cout<<"printing Doubly linked list:"<<endl;
    printDDL(head);
    
    
    return 0;
}


