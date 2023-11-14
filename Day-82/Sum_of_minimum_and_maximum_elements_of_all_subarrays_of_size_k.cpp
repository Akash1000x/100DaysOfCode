// Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
//         K = 4
// Output : 18
// Explanation : Subarrays of size 4 are : 
//      {2, 5, -1, 7},   min + max = -1 + 7 = 6
//      {5, -1, 7, -3},  min + max = -3 + 7 = 4      
//      {-1, 7, -3, -1}, min + max = -3 + 7 = 4
//      {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     
//      Missing sub arrays - 
     
//      {2, -1, 7, -3}
//      {2, 7, -3, -1}
//      {2, -3, -1, -2}
//      {5, 7, -3, -1}
//      {5, -3, -1, -2}
//      and few more -- why these were not considered??
//      Considering missing arrays result coming as 27
     
//      Sum of all min & max = 6 + 4 + 4 + 4 
     
//                           = 18       

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int SumOfKsubArray(vector<int> &arr,int n,int k){
    deque<int> dq1,dq2;
    int sum = 0;
    

    for(int i = 0;i<k;i++){
        //for maximum
        while(!dq1.empty() && arr[i]  >= arr[dq1.back()]){
            dq1.pop_back();
        }
        dq1.push_back(i);

        //for minimum
        while(!dq2.empty() && arr[i]  <= arr[dq2.back()]){
            dq2.pop_back();
        }
        dq2.push_back(i);
    }

    sum = arr[dq1.front()] + arr[dq2.front()];
    

    for(int i = k; i<n ;i++){
        
        // Remove out of window element
        if(!dq1.empty() && i - dq1.front() >= k){
            dq1.pop_front();
        }
        // Remove out of window element
        if(!dq2.empty() && i - dq2.front() >= k){
            dq2.pop_front();
        }  

        //for maximum
        while(!dq1.empty() && arr[i]  >= arr[dq1.back()]){
            dq1.pop_back();
        }
        dq1.push_back(i);

        //for minimum
        while(!dq2.empty() && arr[i]  <= arr[dq2.back()]){
            dq2.pop_back();
        }
        dq2.push_back(i);

        //calculate total
        sum += arr[dq1.front()] + arr[dq2.front()] ;
    }
    return sum;
}


int main()
{
    vector<int> arr = { 2, 5, -1, 7, -3, -1, -2 };

    int k = 3;

    cout << SumOfKsubArray(arr, arr.size(), k);
    return 0;
}