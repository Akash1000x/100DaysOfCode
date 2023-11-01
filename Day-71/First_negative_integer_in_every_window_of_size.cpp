#include <iostream>
#include <queue>
using namespace std;

void firstNegative(vector<int> &A, int K, vector<int> &ans, int N)
{
    queue<int> q;

    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            q.push(i);
        }
    }

    for (int i = K; i < N; i++)
    {
        //push firs negative element answer of window 
        if (!q.empty())
        {
            ans.push_back(A[q.front()]);
        }
        else
        {
            ans.push_back(0);
        }

        //out of window element removing
        if (!q.empty() && q.front() <= i - K)//same i- q.front() >= K
        {
            q.pop();
        }

        //push next element to window
        if (A[i] < 0)
        {
            q.push(i);
        }
    }

    //handling last window
    if (!q.empty())
    {
        ans.push_back(A[q.front()]);
    }
    else
    {
        ans.push_back(0);
    }
}

int main()
{

    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    vector<int> ans;
    int k = 3;
    int n = arr.size();
    firstNegative(arr, k, ans, n);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}