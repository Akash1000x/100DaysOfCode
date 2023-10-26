class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (auto ch : s) {
            if (ch == ']') {
                // Process the part of the string enclosed in []
                string stringToRepeat = "";
                while (!st.empty() && st.top() != "[") {
                    string top = st.top();
                    stringToRepeat += top;
                    st.pop();
                }
                st.pop(); // Remove the '['

                // Extract the numeric value for repetition
                string numericTimes = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    numericTimes += st.top();
                    st.pop();
                }

                reverse(numericTimes.begin(), numericTimes.end());
                int n = stoi(numericTimes);

                // Repeat the string and add it to the stack
                string currentDecode = "";
                while (n--) {
                    currentDecode += stringToRepeat;
                }
                st.push(currentDecode);

            } else {
                // If not ']', add the character to the stack as a string
                string temp(1, ch);
                st.push(temp);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
