class Solution {
public:
    unordered_map<string,int> m;

    string generate(TreeNode *root,vector<TreeNode*> &res){
        if(!root) {
            return "#";
        }
            
        string s=generate(root->left,res) +','+generate(root->right,res)+','+to_string(root->val);

        m[s]++;
        if(m[s]==2) res.push_back(root);
        return s;

    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> ans;
        generate(root,ans);
        return ans;
    }
};