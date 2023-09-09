#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int s, int e, int mid)
{
    //not using extra space and merging in place in the array itself using gap method of shell sort algorithm
    int gap = (e - s + 1) / 2 + (e - s + 1) % 2;

    while (gap > 0)
    {
        int i = s;
        int j = gap + i;
        while (j <= e)
        {
            if (nums[i] > nums[j])
            {
                swap(nums[i], nums[j]);
            }
            j++;
            i++;
        }
        gap = gap / 2 == 0 ? 0 : gap / 2 + gap % 2;
    }
}

void mergesort(vector<int> &nums, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    long mid = s + (e - s) / 2;

    mergesort(nums, s, mid);

    mergesort(nums, mid + 1, e);

    merge(nums, s, e, mid);
}
vector<int> sortArray(vector<int> &nums)
{
    mergesort(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    vector<int> nums{55, 4, 26, 22, 7};
    int n = 5;
    int start = 0;
    int end = n - 1;
    mergesort(nums, start, end);

    for (int i = 0; i < 5; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(1)