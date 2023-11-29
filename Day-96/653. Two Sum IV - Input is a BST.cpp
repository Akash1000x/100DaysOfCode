
class Solution {
    void inorderTraversal(TreeNode*root,vector<int>&v){
        if(root==NULL){
            return ;
        }

        inorderTraversal(root->left,v);
        v.push_back(root->val);
        inorderTraversal(root->right,v);

    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorderTraversal(root,v);
        
        int l = 0;//l = start
        int e = v.size()-1;//e == end
        while(l<e){
            if(v[l] + v[e] == k){
                return true;
            }
            else if(v[l] + v[e] > k){
                e--;
            }
            else if(v[l] + v[e] < k){
                l++;
            }
        }
        return false;
    }
};