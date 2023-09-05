#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    void solve(vector<string> &ans,int index,unordered_map<int,string> &mp,string digits,string output){
        //base case
        if(index >= digits.length()){
            ans.push_back(output);
        }

        int digit = digits[index] -'0';
        string letters  = mp[digit];
        for(int i = 0;i<letters .length();i++){
            char ch = letters [i];
            //include
            output.push_back(ch);
            //recursive call
            solve(ans,index+1,mp,digits,output);
            //backtracking
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        
        if(digits.length() == 0){
            return ans;
        }

        int index =  0;

        unordered_map<int,string> mp{{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};

        string output = "";

        solve(ans,index,mp,digits,output);

        return ans;
    }
};


//Time complexity  -> O(4^n)
//Space complexity -> O(4^n)