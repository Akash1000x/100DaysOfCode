
class Solution {
public:
bool helper(TreeNode* root,long long int min,long long int max){
    if(root == NULL){
        return true;
    }

    if(root->val <= min || root->val >= max) {
        return false;
    }
   

    return  helper(root->left,min,root->val) && helper(root->right,root->val,max);
     

}
    bool isValidBST(TreeNode* root) {
        long long int min = LLONG_MIN;
        long long int max = LLONG_MAX;
        return helper(root,min,max);
    }
};





//or



class Solution {
public:
bool helper(TreeNode* root,long long int min,long long int max){
    if(root == NULL){
        return true;
    }

    if((root->val > min && root->val < max) &&  helper(root->left,min,root->val) && helper(root->right,root->val,max) ) {
        
        return true;
    }

    else{
        return false;
    }
     

}
    bool isValidBST(TreeNode* root) {
        long long int min = LLONG_MIN;
        long long int max = LLONG_MAX;
        return helper(root,min,max);
    }
};



