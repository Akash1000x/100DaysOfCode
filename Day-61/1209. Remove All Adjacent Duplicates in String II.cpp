class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;

        for (char c : s)
        {
            if (st.empty() || st.top().first != c)
            {
                st.push({c, 1});
            }
            else
            {
                st.top().second++;

                if (st.top().second == k)
                {
                    st.pop();
                }//  |
            }    //  |
            //  if (st.top().second == k) {
            //         st.pop();
            // }
        }

        string result = "";

        // Reconstruct the result string
        while (!st.empty())
        {
            char c = st.top().first;
            int count = st.top().second;
            st.pop();
            result = string(count, c) + result;
        }

        return result;
    }
};