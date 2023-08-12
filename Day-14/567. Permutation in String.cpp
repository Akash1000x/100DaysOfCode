#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


class Solution {
private:
    bool checkEqual(int count1[26],int count2[26]){
        for(int i= 0;i<26;i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()){
            return 0;
        }
        int count1[26] = {0};
        int index = 0;
        for(int i = 0;i<s1.size();i++){
            index = s1[i] - 'a';
            count1[index]++;
        }

        int i =0;
        int count2[26] = {0};
        while(i<s1.length()){
            int index = s2[i] -'a';
            count2[index]++;
            i++;
        }

        if(checkEqual(count1,count2)){
            return 1;
        }

        while(i<s2.length()){
            int index = s2[i] -'a';
            count2[index]++;

            int oldchar = s2[i-(s1.length())] -'a';
            count2[oldchar]--;

            if(checkEqual(count1,count2)){
                return 1;
                }

            i++;



        }

        return false;
    }
};