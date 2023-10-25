class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        // stack<int> st;
        int i = 1;
        int j = 0;
        while(i<=n){
            // st.push(i);
            ans.push_back("Push");
            if(i != target[j]){
                // st.pop();
                ans.push_back("Pop");
            }
            else{
                j++;
                if(j==target.size()) break;
            }
            i++;
        }
        return ans;
    }
};