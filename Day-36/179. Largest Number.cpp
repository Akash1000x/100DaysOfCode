bool compare(int a,int b){
        return to_string(a)+to_string(b)> to_string(b)+to_string(a);
    }

class Solution {
public:
    

    string largestNumber(vector<int>& nums) {

        sort(nums.begin(),nums.end(),compare); 
        string ans = "";
        for(auto str:nums){
            ans +=to_string(str);
        }  

        if(ans[0]=='0') return "0";

        return ans;
    }
};



// bool compare(string a,string b){
//         return a+b> b+a;
//     }

// class Solution {
// public:
    

//     string largestNumber(vector<int>& nums) {
//         vector<string> snums;
//         for(auto s:nums){
//             snums.push_back(to_string(s));
//         }
//         sort(snums.begin(),snums.end(),compare); 
//         string ans = "";
//         for(auto str:snums){
//             ans += str;
//         }  

//         if(ans[0]=='0') return "0";

//         return ans;
//     }
// };

