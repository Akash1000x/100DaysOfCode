class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0;i<n;i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }

        while(maxi != mini){
            if(maxi > mini){
                maxi = maxi - mini;
            }else{
                mini = mini - maxi;
            }
        }
        return maxi;
    }
};