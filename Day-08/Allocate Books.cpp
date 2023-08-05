#include <bits/stdc++.h>

bool isPossible(int n, int m, vector<int> time, long long mid)
{

    int daysCount = 1;

    long long timeSum = 0;

    for (int i = 0; i < m; i++)
    {

        if (timeSum + time[i] <= mid)
        {

            timeSum += time[i];
        }

        else
        {

            daysCount++;

            if (daysCount > n || time[i] > mid)
            {

                return false;
            }

            timeSum = time[i];
        }
    }

    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)

{

    // Write your code here.

    long long s = 0;

    long long sum = 0;

    for (int i = 0; i < time.size(); i++)
    {

        sum += time[i];
    }

    long long e = sum;

    long long ans = -1;

    long long mid = s + (e - s) / 2;

    while (s <= e)
    {

        if (isPossible(n, m, time, mid))
        {

            ans = mid;

            e = mid - 1;
        }

        else
        {

            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}