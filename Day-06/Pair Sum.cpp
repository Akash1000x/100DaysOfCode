#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> ans;
   sort(arr.begin(),arr.end());
   for(int i=0;i<arr.size()-1;i++)
   {
      for(int j = i+1;j<arr.size();j++){
         if(arr[i]+arr[j]==s){
            vector<int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            ans.push_back(temp);
         }

      }
   }
   return ans;
}