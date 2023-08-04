int firstOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}


#include <bits/stdc++.h> 
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;
    // int ans1=-1;
    // int ans2 = -1;
    // for(int i=0;i<n;i++){
    //     if(arr[i]==k){
    //         ans1 = i;;
    //         break;
    //     }
    // }
    // for(int j=n-1;j>=0;j--){
    //     if(arr[j]==k){
    //         ans2=j;
    //         break;
    //     }
    // }


    // p.first=ans1;
    // p.second = ans2;
    // p.first=-1;
    // p.second=-1;
    // for(int i=0;i<n;i++){
    //     if(k != arr[i]){
    //         continue;
    //     }
    //     else if(p.first == -1){
    //         p.first=i;
    //     }
        
    //         p.second=i;
        
    // }
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    return p;
}