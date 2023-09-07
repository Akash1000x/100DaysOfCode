
//hacker rank problem link: https://www.hackerrank.com/challenges/ctci-merge-sort/problem
long merge(vector<int> &arr,vector<int> &temp,int start,int end){

    int mid = (start+end)/2;
    long  c = 0;

    int mainIndex = start;
    int i = start;
    int j = mid+1;

    while(mid >= i && end >= j){
        if(arr[i] <= arr[j]){
            temp[mainIndex++] = arr[i++];
        }
        else{
            temp[mainIndex++] = arr[j++];
            c += mid - i +1;
        }
    }

    while (mid >= i)
    {
        temp[mainIndex++] = arr[i++];
    }
    
    while (end >= j)
    {
        temp[mainIndex++] = arr[j++];
    }
    
    while(start <= end){
        arr[start] = temp[start];
        start++;
    }
    return c;
}



//Recurison function
long mergSort(vector<int> &arr,vector<int> &temp,int start,int end){

    if(start>=end){
        return 0;
    }

    int mid = (start+end)/2;
    long c = 0;
    //sorting left half of array
    c += mergSort(arr,temp,start,mid);

    //sorting right half of array
    c += mergSort(arr,temp,mid+1,end);

    //merge sorted array
    c += merge(arr,temp,start,end);

    return c;

}

long countInversions(vector<int> arr) {
   long count = 0;
   int end = arr.size()-1;
   vector<int> temp(arr.size());
   count = mergSort(arr,temp,0,end);
   return count;

}



// or  


#include<iostream>
#include<vector>
using namespace std;


int merge(int *arr,int start,int mid,int end){

    // int mid = (start+end)/2;
    int c = 0;
    int len1 = mid - start +1;
    int len2 = end - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int mainIndex = start;
    for(int i = 0;i<len1;i++){
        arr1[i] = arr[mainIndex++];  
    }

    mainIndex = mid+1;
    for(int i = 0;i< len2;i++){
        arr2[i] = arr[mainIndex++];
    }

    mainIndex = start;
    int index1=0;
    int  index2 = 0;

    while(len1 > index1 && len2 > index2){
        if(arr1[index1] <= arr2[index2]){
            arr[mainIndex++] = arr1[index1++];
        }
        else{
            arr[mainIndex++] = arr2[index2++];
            c += len1 - index1;                   //main change for counting inversions
        }
    }

    while (len1 > index1)
    {
        arr[mainIndex++] = arr1[index1++];
    }
    
    while (len2 > index2)
    {
        arr[mainIndex++] = arr2[index2++];
    }
    
    delete []arr1;
    delete []arr2;

    return c;
}



//Recurison function
int mergSort(int *arr,int start,int end){

    if(start>=end){
        return 0;
    }

    int mid = (start+end)/2;
    long c = 0;
    //sorting left half of array
    c += mergSort(arr,start,mid);

    //sorting right half of array
    c += mergSort(arr,mid+1,end);

    //merge sorted array
    c += merge(arr,start,mid,end);

    return c;

}

int main(){
    int arr[] = {1,1,1,2,2};
    int n = 5;
    int start = 0;
    int end = n-1;
    int c = mergSort(arr,start,end);
    cout << c << endl;
    // for(int i = 0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}