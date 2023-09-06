#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    void solve(string &num1, string &num2,int &carry,string &result,int i,int j){

        if(i < 0  && j < 0){
            if(carry >0){
            // result = to_string(carry) + result;
                result.push_back(carry+'0');
            }
            return;
        }

        int a = (i>= 0) ? num1[i]-'0' : 0;
        int b = (j>= 0) ? num2[j]-'0' : 0;

        int c = a+b + carry;

        carry = c/10;

        int digit = c%10;

        // result  = to_string(c%10) + result;
        result.push_back(digit+'0');

        solve(num1,num2,carry,result,i-1,j-1);

      

    }
    string addStrings(string num1, string num2) {
        
        int i = num1.length()-1;
        int j =  num2.length()-1;

        int carry = 0;
        string result = "";
        //recursive solution
        solve(num1,num2,carry,result,i,j);

        reverse(result.begin(),result.end());


// itretive approach

        // int addition = 0;
        // while(i>=0 || j>= 0 || carry>0){

        //  int a = (i>= 0) ? num1[i]-'0' : 0;
        //  int b = (j>= 0) ? num2[j]-'0' : 0;


        //     int c = a+b + carry;

        //     carry = c/10;

        //     addition = c%10;

        //     result = to_string(addition) + result;

            
        //     i--; 
        //     j--;

        // }


        return result;
    }
};


//Time complexity  -> O(n)
//Space complexity -> O(n)