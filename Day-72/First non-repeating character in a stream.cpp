
class Solution
{
public:
    string FirstNonRepeating(string s)
    {
        queue<char> q;
        vector<int> arr(26, 0);
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {

            arr[s[i] - 'a']++;
            // This character is unique, add it to the queue
            if (arr[s[i] - 'a'] == 1)
                q.push(s[i]);

             // Check if the front of the queue is still the first non-repeating character
            while (!q.empty() && (arr[q.front() - 'a'] > 1))
            {
                q.pop();
            }

            if (!q.empty())
            {
                ans += q.front();
            }
            else
            {
                ans.push_back('#');// No unique character found
            }
        }
        return ans;
    }
};


// tc = O(n)
// sc = O(n)