class Solution {
public:
    long long smallestNumber(long long num) {

        string nums = to_string(num);

        if(num > 0){
            sort(nums.begin(),nums.end());
        }

        else{
            sort(nums.begin()+1,nums.end());//handling - in num 
        }

        int i = 0;
        while(nums[i] == '0' && i<nums.size()){
            i++;
        }

        if(num>0){
            swap(nums[0],nums[i]);
        }
        else{
            reverse(nums.begin(),nums.end());
            nums = "-" + nums;
        }
        // stoll(or use stoi) using for change long string int 
        long long int n = stoll(nums); 
        return n;
        
    }
};