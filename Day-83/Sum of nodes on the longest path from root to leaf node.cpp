class Solution
{
    void helper(Node* &root,int &n,int &ans,int &k,int sum){
        if(root== NULL){
            return;
        }
        
        sum = sum+root->data;
        k++;
        
        if(root->left == NULL && root->right == NULL ){
            if(k==n && sum>ans){
                ans = sum;
                n = k;
                
            }
            else if(k > n){
                ans = sum;
                n = k;
            }
        }
        
        helper(root->left,n,ans,k,sum);
        helper(root->right,n,ans,k,sum);
        
        //backtrack
        k--;
        
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int n = 0;
        int ans = 0;
        int k = 0;
        int sum = 0;
        
        helper(root,n,ans,k,sum);
        return ans;
    }
};