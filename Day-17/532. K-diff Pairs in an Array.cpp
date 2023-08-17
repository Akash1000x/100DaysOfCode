#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        set<pair<int,int>> ans;

        int n = nums.size();
        int count = 0;
        for(int i= 0;i<n;i++){

            for(int j = i+1;j<n;j++){

                if((nums[j]-nums[i]==k)){
                    ans.insert({nums[i],nums[j]});
                }

            }
        }
        return ans.size();
    }
};

//or

class Solution {
private:
    int binerysearch(vector<int>& nums,int start ,int element){

        int end = nums.size()-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(nums[mid] == element){
                return mid;
            }
            else if(nums[mid] > element){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return -1;

    }
public:
    int findPairs(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        set<pair<int,int>> ans;

        int n = nums.size();
        int count = 0;
        for(int i= 0;i<n;i++){

            if(binerysearch(nums , i+1 ,nums[i]+k) != -1){
                ans.insert({nums[i],nums[i]+k});
            }
            
        }
        return ans.size();
    }
};


//or


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>> ans;
        int n = nums.size();
        int i = 0;
        int j = 1;
        while(j<n){
            if(nums[j] - nums[i] ==k){
                ans.insert({nums[i],nums[j]});
                ++i;
                ++j;
            }
            else if(nums[j] - nums[i] <k){
                j++;
            }
            else{
                i++;
            }
            if(i==j) j++;
        }
        return ans.size();
    }
};