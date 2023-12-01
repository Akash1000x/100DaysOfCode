#include<iostream>
#include<queue>
#include<vector>
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



void inorderTraversal(Node* root,vector<int>&arr1){
    // base case
    if(root == NULL){
        return;
    }
    // Left 
    inorderTraversal(root->left,arr1);
    // Node
    arr1.push_back(root->data);
    // Right
    inorderTraversal(root->right,arr1);
}

vector<int> mergeArray(vector<int>&arr1,vector<int>&arr2){
    vector<int> arr3;
    

    int i = 0;
    int j = 0;

    while(i < arr1.size() && j < arr2.size() ){

        if(arr1[i] <= arr2[j] ){
            arr3.push_back(arr1[i]);
            i++;
        }
        else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    
    while(i < arr1.size()){
        arr3.push_back(arr1[i]);
        i++;
    }

    while(j < arr2.size()){
        arr3.push_back(arr2[j]);
        j++;
    }

    return arr3;

}

Node* CreatingAnsTree(vector<int> &mergeArray,int s,int e){
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;
    Node*root = new Node(mergeArray[mid]);

    root->left = CreatingAnsTree(mergeArray,s,mid-1);
    root->right = CreatingAnsTree(mergeArray,mid+1,e);
    return root;
}


//level order traversal
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
void inorderTraversal1(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // Left 
    inorderTraversal1(root->left);
    // Node
    cout<<root->data<<" ";
    // Right
    inorderTraversal1(root->right);
}


int main(){
    Node*root1 = NULL;
    cout<<"Enter the data for first Tree "<<endl;
    takeInput(root1);
    //intput 100 50 200 10 60 150 250 -1 

    //creating second tree
    Node*root2 = NULL;
    cout<<"Enter the data for second Tree "<<endl;
    takeInput(root2);
    //input 70 40 300 350 5 -1

    //convert tree to array
    vector<int> arr1;
    inorderTraversal(root1,arr1);

    vector<int> arr2;
    inorderTraversal(root2,arr2);

    //merging both arrays
    vector<int> mergedArray = mergeArray(arr1,arr2);

    
    cout<<endl;
    //creating tree by merged array
    Node*root3 = CreatingAnsTree(mergedArray,0,mergedArray.size()-1);

    cout<<endl;
    cout<<"Printing the tree by level order traversal"<<endl;
    levelOrderTraversal(root3);    
    return 0;
}


