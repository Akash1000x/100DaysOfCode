class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int n= arr.size(); 
        int e=n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
                return mid;
            }
            else if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]){
                e=mid;
            }
            else if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1]){
                s=mid+1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
        // int n = arr.size();
        // int start = 0;
        // int end = n-1;
        // int mid=start+(end-start)/2;
        // while(start<=end){
        //     if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
        //         return mid;
        //     }else if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]){
        //         end=mid;
        //     }else if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1]){
        //         start=mid+1;
        //     }
        //     mid=start+(end-start)/2;
        // }
        
        // return -1;
        
    }
};