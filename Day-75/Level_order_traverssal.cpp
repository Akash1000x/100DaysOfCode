#include <iostream>
#include <queue>
using namespace std;

// creating a node
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

Node *builder()
{

    int data;
    cout << "enter the element to insert:";
    cin >> data;

    // -1 data indicates that we have the leaf node (Base Case)
    if (data == -1)
    {
        return NULL;
    }
    // Create the root node and hence solved 1 case
    Node *root = new Node(data);

    // Recursion will handle
    cout << "Enter the data for left part of " << data << " Node" << endl;
    root->left = builder();

    cout << "Enter the data for right part of " << data << " Node" << endl;
    root->right = builder();

    return root;
}

//  level order traversal 
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
    Node *root = builder();

    levelOrderTraversal(root);

    return 0;
}