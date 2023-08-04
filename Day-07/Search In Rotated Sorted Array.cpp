int pivotelement(vector<int>& arr, int n){
    int s=0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(arr[mid] >= arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int solution(vector<int>& arr,  int k,int s,int e){
    // int s=0;
    // int e = n-1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]<k){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}



int search(vector<int>& arr, int n, int k)
{
    int pivot = pivotelement(arr,  n);
    if(arr[n-1] >= k && arr[pivot]<=k )
    {
        return solution(arr,k,pivot,n-1);
    }
    else{
        return solution(arr,k,0,pivot-1);
    }
    return -1;
    // int s =0;
    // int e = n-1;
    // int mid = s + (e-s)/2;
    // while(s<=e){
    //     if(arr[mid]==k){
    //         return mid;
    //     }
    //     else if(arr[0]>k){
    //         s = mid+1;
    //     }
    //     else{
    //         e = mid-1;
    //     }
    //     mid = s + (e-s)/2;
    // }
    // return -1;
}
