#include <bits/stdc++.h>

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{

    int num1 = 0, num2 = 0;

    for (int i = 0; i < n; i++)
    {
        num1 = num1 * 10 + a[i];
    }
    for (int j = 0; j < m; j++)
    {
        num2 = num2 * 10 + b[j];
    }
    int sum = num1 + num2;
    int len = log10(sum) + 1;

    vector<int> c;

    for (int k = 0; k < len; k++)
    {

        int num = sum % 10;
        c.push_back(num);
        sum = sum / 10;
    }
    reverse(c.begin(), c.end());
    return c;
}