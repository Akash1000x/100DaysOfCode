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


void levelOrderTraversal(Node *root)
{

    queue<Node *> q;
    // push root element in queue
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
         if(q.front() == NULL){
             cout<<endl;
             q.pop();
             if(!q.empty()){
                 q.push(NULL);
             }
         }

        Node *temp = q.front();

        q.pop();

        cout << temp->data << " ";

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    Node*root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    levelOrderTraversal(root);
    return 0;
}


//or



// #include <iostream>
// #include <queue>
// using namespace std;

// // creating a node
// class Node
// {

// public:
//     int data;
//     Node *left;
//     Node *right;

// };

// Node* newNode(int data){
//     Node* child = new Node();
//     child->data = data;
//     child->left = NULL;
//     child->right = NULL;

//     return child;
// }

// void levelOrderTraversal(Node *root)
// {

//     queue<Node *> q;
//     // push root element in queue
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty())
//     {
//          if(q.front() == NULL){
//              cout<<endl;
//              q.pop();
//              if(!q.empty()){
//                  q.push(NULL);
//              }
//          }

//         Node *temp = q.front();

//         q.pop();

//         cout << temp->data << " ";

//         if (temp->left)
//         {
//             q.push(temp->left);
//         }

//         if (temp->right)
//         {
//             q.push(temp->right);
//         }
//     }
// }

// int main()
// {
//     Node*root = newNode(10);
//     root->left = newNode(20);
//     root->right = newNode(30);
//     root->left->left = newNode(40);
//     root->left->right = newNode(50);

//     levelOrderTraversal(root);
//     return 0;
// }


