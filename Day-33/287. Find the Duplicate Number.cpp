class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        while(nums[0] != nums[nums[0]]){
            
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
        
        // for(int i = 0;i<nums.size();i++){
        //     int index = abs(nums[i]);
        //     if(nums[index] <0  ){
        //         return index;

        //     }
        //     else{
        //         nums[index] *= (-1);
        //     }

        // }
        // return -1;
        
       //or



        // sort(nums.begin(),nums.end());
        //     for(int j= 0;j<nums.size()-1;j++){
        //         if(nums[j]==nums[j+1]){
        //             return nums[j];
        //         }
        //     }
        
        // return 0;
    }
};