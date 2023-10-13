class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st; // Create a stack to store opening brackets.

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            // Check if the character is an opening bracket.
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch); // Push opening bracket onto the stack.
            }
            else
            {
                if (!st.empty())
                { // If the stack is not empty.
                    // Get the top character from the stack.
                    char topchar = st.top();

                    // Check if the current character matches the top character in the stack for valid pairs.
                    if (ch == ')' && topchar == '(')
                    {
                        st.pop(); // Matching brackets, pop from the stack.
                    }
                    else if (ch == '}' && topchar == '{')
                    {
                        st.pop(); // Matching brackets, pop from the stack.
                    }
                    else if (ch == ']' && topchar == '[')
                    {
                        st.pop(); // Matching brackets, pop from the stack.
                    }
                    else
                    {
                        return false; // Brackets do not match, return false.
                    }
                }
                else
                {
                    return false; // No opening bracket to match, return false.
                }
            }
        }


        if (st.empty())
        {
            return true; // If the stack is empty, all brackets were matched, so return true.
        }
        else
        {
            return false; // If the stack is not empty, not all brackets were matched, so return false.
        }
    }
};
