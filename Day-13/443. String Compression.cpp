#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {

        int i = 0;
        int n = chars.size();
        int ansIndex = 0;

        while(n>i){

            int j = i+1;
            while(j<n && chars[i] == chars[j]){
                j++;
            }
            
            chars[ansIndex++]= chars[i];

            int count = j-i;

            if(count > 1){

                string s = to_string(count);

                for(char ch:s){
                    chars[ansIndex++]=ch;
                }
            }

            i = j;
        }    

        return ansIndex;
    }
};