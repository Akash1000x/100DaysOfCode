
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
void helper(Node *root,map<int,vector<int>> &mp,int d){
    if(root==NULL){
        return;
    }
    mp[d].push_back(root->data);
    
    helper(root->left,mp,d+1);
    helper(root->right,mp,d);
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    map<int,vector<int>> mp;
    helper(root,mp,0);
    
    for(auto& it:mp){
        for(auto i:it.second){
            ans.push_back(i);
        }
    }
    return ans;
}

//or


vector<vector<int> > result;
void diagonalPrint(Node* root)
{
    if (root == NULL)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        int size = q.size();
        vector<int> answer;
 
        while (size--) {
            Node* temp = q.front();
            q.pop();
 
            // traversing each component;
            while (temp) {
                answer.push_back(temp->data);
 
                if (temp->left)
                    q.push(temp->left);
 
                temp = temp->right;
            }
        }
        result.push_back(answer);
    }
}
 