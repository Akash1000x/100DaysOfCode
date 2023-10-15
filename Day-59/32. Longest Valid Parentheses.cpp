class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Initialize the stack with -1 to handle edge cases.

        int maxLen = 0; // Initialize the maximum valid length.
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push the index onto the stack for an opening parenthesis.
            } else {
                st.pop(); // Pop the top element from the stack for a closing parenthesis.

                if (st.empty()) {
                    st.push(i); // If the stack is empty, push the current index, indicating a new starting point.
                } else {
                    maxLen = max(maxLen, i - st.top()); // Calculate the valid length.
                }
            }
        }
        return maxLen; // Return the maximum valid length.
    }
};
