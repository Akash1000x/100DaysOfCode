class Solution
{
public:
    void solve(vector<string> &ans, int n, int open, int close, string output)
    {
        if (open >= n && close >= n)
        {
            ans.push_back(output);
            return;
        }

        // intclude open bracket
        if (open < n)
        {

            output.push_back('(');
            solve(ans, n, open + 1, close, output);
            // backtrack
            output.pop_back();
        }

        // include close bracket
        if (open > close)
        {
            output.push_back(')');

            solve(ans, n, open, close + 1, output);
            // backtrack
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {

        vector<string> ans;
        int open = 0;
        int close = 0;
        string output = "";
        solve(ans, n, open, close, output);
        return ans;
    }
};