// example-
// Input:
//              10
//           /      \
//         -2        6
//        /   \     /  \
//      8     -4   7    5

// Output:
//             20
//           /    \
//         4        12
//        /  \     /  \
//      0     0   0    0

// Explanation:

//            (4-2+12+6)
//           /           \
//       (8-4)          (7+5)
//        /   \         /  \
//       0     0       0    0

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int toSum(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftSum = toSum(node->left);
        int rightSum = toSum(node->right);

        int originalValue = node->data; // Save the original value

        // Update the node's value with the sum of left and right subtrees
        node->data = leftSum + rightSum;//update in current node

        return originalValue + node->data;//return to parent node
    }

    Node *toSumTree(Node *node)
    {
        toSum(node);
        return node; // Return the root of the modified tree
    }
};

void printTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    // Print in-order (Left, Root, Right) for better visualization
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main()
{
    // Create a sample binary tree
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    cout << "Original Tree: ";
    printTree(root);
    cout << endl;

    // Create a solution object
    Solution solution;

    // Call the toSumTree function to convert the tree to a sum tree
    Node *modifiedRoot = solution.toSumTree(root);

    // Print the modified tree

    cout << "Modified Tree: ";
    printTree(modifiedRoot);
    cout << endl;

    return 0;
}
