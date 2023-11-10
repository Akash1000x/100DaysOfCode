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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }

        if(p == NULL || q == NULL){
            return false;
        }

        if(p->val != q->val){
            return false;
        }

       
        return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }
};





//or





class Solution {
    vector<int> traversal(TreeNode* root,vector<int> &arr){
        if(root == NULL){
            arr.push_back(NULL);
            return arr;
        }

        arr.push_back(root->val);

        traversal(root->left,arr);

        traversal(root->right,arr);

        return arr;

    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        vector<int> arr1;
        vector<int> arr2;

        traversal(p,arr1);
        traversal(q,arr2);
        if(arr1.size() != arr2.size()){
            return false;
        }

        for(int i = 0;i<arr1.size();i++){
            cout<<arr1[i]<<" ";
            cout<<arr2[i]<<" ";
            if(arr1[i] != arr2[i]){
                return false;
            }
        }

        return true;
    }
};