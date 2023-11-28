
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {

        if(root == NULL){
            return -1;
        }

        int leftans = kthSmallest(root->left,k);

        if (leftans != -1){
            return leftans;
        }

        k--;
        if(k == 0){
            return root->val;

        }
        int rightans =  kthSmallest(root->right,k);
        return rightans;

    }
};

//or


class Solution {
    
void helper(TreeNode* root,int &k,int &ans){
    if(root == NULL){
        return;
    }

    helper(root->left,k,ans);

    k--;
    if(k == 0){
        ans = root->val;
        return;
    }

    helper(root->right,k,ans);
    
} 

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
    
        helper(root,k,ans);
        return ans;
        
    }
};


