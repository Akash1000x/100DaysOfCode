class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=(nums.size()-1);i>=0;i--){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);
            }
        }
        return nums.size();
        
    }
};