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



class NodeData{
    public:
    int size;
    int maxValue;
    int minValue;
    bool validBST;
    
    NodeData(){

    }

    NodeData(int size,int maxValue,int minValue,bool validBST){
        this->size = size;
        this->maxValue = maxValue;
        this->minValue = minValue;
        this->validBST = validBST;
    }
};



//finding largest bst
NodeData* findLargestBST(Node*root,int&ans){
    if(root == NULL){
        NodeData*temp = new NodeData(0,INT_MIN,INT_MAX,true);
        return temp;
    }
    // First find left subtree answer
    NodeData*leftKaAns = findLargestBST(root->left,ans);
    // Then find right subtree answer
    NodeData*rightKaAns = findLargestBST(root->right,ans);
    
    // Checking starts here
    NodeData*currNodeKaAns = new NodeData();

    currNodeKaAns->size = leftKaAns->size + rightKaAns->size+1;
    currNodeKaAns->maxValue = max(root->data,rightKaAns->maxValue);
    currNodeKaAns->minValue = min(root->data,leftKaAns->minValue);
    
    if(leftKaAns->validBST && rightKaAns->validBST && root->data>leftKaAns->maxValue && root->data<rightKaAns->minValue){
        currNodeKaAns->validBST = true;
    }
    else{
        currNodeKaAns->validBST = false;
    }

    if(currNodeKaAns->validBST){
        ans = max(ans,currNodeKaAns->size);
    }
    return currNodeKaAns;
}



int main(){
    Node* root = new Node(5);
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(1);
    Node* fourth = new Node(3);
    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;
    int ans = 0;
  
    findLargestBST(root,ans);
    cout<<"Largest BST size = "<<ans<<endl;
   
    return 0;
}
