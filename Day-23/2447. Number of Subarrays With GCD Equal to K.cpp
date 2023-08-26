class Solution {


public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

    for (int start = 0; start < n; start++) {
        int currentGCD = nums[start];
        if (currentGCD == k) {
            count++;
        }
        for (int end = start + 1; end < n; end++) {
            currentGCD = gcd(currentGCD, nums[end]);
            if (currentGCD == k) {
                count++;
            }
        }
    }
    return count;
    }
};
