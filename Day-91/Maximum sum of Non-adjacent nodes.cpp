// Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

// Input:
//         1
//       /   \
//      2     3
//     /     /  \
//    4     5    6
// Output: 16
// Explanation: The maximum sum is sum of
// nodes 1 4 5 6 , i.e 16. These nodes are
// non adjacent.

class Solution{
  public:
  pair<int,int> helper(Node* root){

      if(root == NULL){
          return {0,0};
      }
      
      auto left = helper(root->left);
      auto right = helper(root->right);
      
        int a =  root->data + left.second + right.second;
        
        int b = max(left.first ,left.second) + max(right.first,right.second);
        
        return{a,b};
        
  }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        auto ans = helper(root);
        return max(ans.first,ans.second);
    }
};