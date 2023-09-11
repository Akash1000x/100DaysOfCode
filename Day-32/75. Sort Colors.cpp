class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;
        int medium = 0;
        int high = nums.size()-1;
        while(medium <= high){
            if(nums[medium] == 0){
                swap(nums[low],nums[medium]);
                low++;medium++;
            }
            else if(nums[medium] == 1){
                medium++;
            }
            else{
                swap(nums[medium],nums[high]);
                high--;
            }
        }
    }
        
    //     int zero = 0;
    //     int one = 0;
    //     int two = 0;
    //     for(int i = 0;i<nums.size();i++){
    //         if(nums[i] == 0){
    //             zero++;
    //         }
    //         else if(nums[i] == 1){
    //             one++;
    //         }
    //         else{
    //             two++;
    //         }

    //     }

    //     for(int i = 0;i<nums.size();i++){
    //         if(zero > 0){
    //             nums[i] = 0;
    //             zero--;
    //         }
    //         else if (one > 0){
    //             nums[i] = 1;
    //             one--;
    //         }
    //         else{
    //             nums[i] =2;
    //         }
    //     }
    // }
};