#include <iostream>
#include <queue>
#include<vector>
#include<map>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(){
    int data;
    cout<<"Enter the element to insert:";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);

   // Recursion will handle
    cout << "for left part of " << data << " Node " ;
    root->left = buildTree();

    cout << "for right part of " << data << " Node " ;
    root->right = buildTree();

    return root;
}



// Left view
void printLeftView(Node* root,vector<int>&ans,int level){
    // Base case
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    printLeftView(root->left,ans,level+1);

    printLeftView(root->right,ans,level+1);
}
int main()
{
    Node* root = buildTree();
    vector<int>ans;
    printLeftView(root,ans,0);
    // Print the left view

    cout<<"Left view of Tree:";
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}