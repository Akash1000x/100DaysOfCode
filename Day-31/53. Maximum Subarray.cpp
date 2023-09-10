
//using kadane's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int maxSum = nums[0];
        int i = 0;
        while(i<nums.size()){
            
            sum += nums[i];

            maxSum = max(maxSum,sum);
            
            if(sum < 0){
                sum = 0;
            }
            i++;
        }
        return maxSum;
    }
};



//or

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum = nums[0];
//         int maxSum = nums[0];
//         int i = 1;
//         while(i<nums.size()){

//             sum  = max(nums[i],sum+nums[i]); 

//             maxSum = max(maxSum,sum);
            
//             i++;
//         }
//         return maxSum;
//     }
// };