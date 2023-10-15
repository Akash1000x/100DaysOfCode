#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkRedundancy(string s) {
        stack<char> st; // Initialize a stack to track parentheses and operators
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            if (ch == '(') {
                st.push(ch); // Push opening parentheses onto the stack
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                st.push(ch); // Push operators onto the stack
            }
            
            if (ch == ')') {
                bool flag = 1; // Initialize a flag for checking redundancy
                
                while (!st.empty() && st.top() != '(') {
                    if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                        flag = 0; // If an operator is encountered between parentheses, set the flag to 0
                    }
                    st.pop(); // Pop elements from the stack until the matching opening parenthesis is found
                }
                st.pop(); // Pop the matching opening parenthesis
                
                if (flag == 1) {
                    return flag; // If the flag is still 1, there are redundant parentheses
                }
            }
        }
        
        return 0; // No redundant parentheses found
    }
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        string s;
        cin >> s;
    //example  s = ((a+b))
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout << res << endl;
    }
}

