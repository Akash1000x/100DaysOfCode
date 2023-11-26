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


Node* deleteNodeInBST(Node*root,int target){

    if(root == NULL){
        return root;
    }

    if(root->data == target){
        //Leaf Node
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        //Left child not exist
        else if(root->left != NULL && root->right == NULL){
            Node*child = root->left;
            delete root;
            return child;
        }
        //Right child not exist
        else if(root->left == NULL && root->right != NULL){
            Node*child = root->right;
            delete root;
            return child;
        }
        //Both child exists
        else{
            int inorderPred = maxValue(root->left);

            root->data = inorderPred;

            root->left = deleteNodeInBST(root->left,inorderPred);
            return root;
        }
    }
    else if(root->data > target){
        
        root->left = deleteNodeInBST(root->left,target);
    }
    else{
        root->right = deleteNodeInBST(root->right,target);
    }
    return root;

}



void levelOrderTraversal(Node *root)
{
    // Empty tree
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // Push the root in queue
    q.push(root);
    q.push(NULL);
    // Run the loop until queue becomes empty
    while (!q.empty())
    {
        // Fetch front node and then pop
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // go to the next line
            cout << endl;
            // Marking for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // left child exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // right child exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main(){
    Node*root = NULL;
    cout<<"Enter the data for Node"<<endl;
    takeInput(root);

    // example input 10 5 20 4 6 70 80 50 15 -1
    cout<<"Before deletion BST"<<endl;
    levelOrderTraversal(root);
    
    //deletion
    deleteNodeInBST(root,10);


    cout<<"After deletion BST"<<endl;
    levelOrderTraversal(root);


    return 0;
}


