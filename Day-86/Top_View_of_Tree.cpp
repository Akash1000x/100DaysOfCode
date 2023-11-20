#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node
{
public:
    int data ;
    Node* left;
    Node* right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
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
    cout << "Enter the data for left part of " << data << " Node" << endl;
    root->left = buildTree();

    cout << "Enter the data for right part of " << data << " Node" << endl;
    root->right = buildTree();

    return root;
}


void topView(Node*root){

    if(root == NULL){
        return;
    }
   // Map storing node and horizontal distance from root (only once)
    map<int,int>topNode; 
    // Level order traversal
    // Create a queue consisting of pair having Node* and horizontal distance
    queue<pair<Node*,int>> q;
    // Push root node and horizontal distance of root node
    q.push({root,0});

    while(!q.empty()){
        Node* temp = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Check whether node corresponding to horizontal distance is present in map or not
        // If yes then ignore the node else store the node
        if(topNode.find(hd) == topNode.end()){
            // The above condition tells that entry is not present
            // Create the entry
            topNode[hd] = temp->data;
        }

        if(temp->left){
            q.push(make_pair(temp->left,hd-1));
        }

        if(temp->right){
            q.push(make_pair(temp->right,hd+1));
        }


    }

    cout<<"Printing the top view"<<endl;
    for(auto i:topNode){
        cout<<i.first <<"->"<<i.second<<endl;
    }
}

int main(){
    Node* root = buildTree();

    vector<int> ans;
    topView(root);
    return 0;
}