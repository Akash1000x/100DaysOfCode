#include<iostream>
#include<vector>
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

//
Node* constructTreeByInOrder(vector<int> &v,int s,int e){
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;
    int element = v[mid];
    Node*root = new Node(element);

    root->left = constructTreeByInOrder(v,s,mid-1);
    root->right = constructTreeByInOrder(v,mid+1,e);
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

int main(){
    vector<int> v{1,2,3,4,5,6,7,8,9};

    Node* root = constructTreeByInOrder(v,0,8);

    levelOrderTraversal(root);
    return 0;
}