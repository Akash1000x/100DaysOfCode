#include <iostream>
#include <queue>
#include <unordered_map>
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
        this->left = NULL;
        this->right = NULL;
    }
};

int findPosition(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void createMapping(unordered_map<int,int> &mapping,int n,int inorder[]){
    for(int i = 0;i<n;i++){
        mapping[inorder[i]] = i;
    }
}


Node *buildTree(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd,unordered_map<int,int> &mapping)
{

    if (preIndex >= size || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Find the root node of the tree and we get this from preorder traversal
    int element = preorder[preIndex++];
    // Create root node for this element
    Node *root = new Node(element);
    
    //find index using array
    // int pos = findPosition(inorder, size, element);

    //or  find index using map
    int pos = mapping[element];

    root->left = buildTree(inorder, preorder, size, preIndex, inorderStart, pos - 1,mapping);

    root->right = buildTree(inorder, preorder, size, preIndex, pos + 1, inorderEnd,mapping);

    return root;
}

void levelOrderTraversal(Node *root)
{

     queue<Node *> q;
    // push root element in queue
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
         
        Node *temp = q.front();

        q.pop();

        if (temp== NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // printing node element
            cout << temp->data << " ";

            // check left root nood exist or not
            if (temp->left)
            {
                // if exist push it in queue
                q.push(temp->left);
            }

            // check right root nood exist or not
            if (temp->right)
            {
                // if exist push it in queue
                q.push(temp->right);
            }
        }
        
    }
}


int main()
{
    int inorder[] = {40, 20, 50, 10, 60, 30, 70};
    int preorder[] = {10, 20, 40, 50, 30, 60, 70};
    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    unordered_map<int,int> mapping;
    createMapping(mapping,size,inorder);
    
    cout<<"Building tree"<<endl;
    Node* root = buildTree(inorder,preorder,size,preIndex,inorderStart,inorderEnd,mapping);
    cout<<"Printing the tree"<<endl;
    levelOrderTraversal(root);

    return 0;
}


//or 



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    TreeNode*helper(vector<int>& preorder, vector<int>& inorder,int size,int &preIndex,int inorderStart,int inorderEnd,unordered_map<int,int> &mapping){
        //base case
        if(preIndex >= size || inorderStart > inorderEnd){
            return NULL;
        }

        int element = preorder[preIndex++];

        TreeNode*root = new TreeNode(element);

        int p = mapping[element];

        root->left = helper(preorder,inorder,size,preIndex,inorderStart,p-1,mapping);

        root->right = helper(preorder,inorder,size,preIndex,p+1,inorderEnd,mapping);
        

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = size-1;

        unordered_map<int,int> mapping;
        for(int i = 0;i<size;i++){
            mapping[inorder[i]] = i;
        }

        return  helper(preorder,inorder,size,preIndex,inorderStart,inorderEnd,mapping);
        
    }
};