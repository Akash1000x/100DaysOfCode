#include<iostream>
#include<vector>
using namespace std;

int partition(int *arr,int left,int right){
    int pivot = arr[left];
    int count = 0;
    for(int i = left+1;i<=right;i++){
        if(pivot >= arr[i])
            count++;
    }

    int pivotIndex = left + count ;
    swap(arr[pivotIndex],arr[left]);

    int i = left;
    int j = right;

    while (i < pivotIndex && j > pivotIndex)
    {
        while(pivot >= arr[i]){
            i++;
        }
        while(pivot < arr[j]){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;    
}


void quickSort(int *arr,int left,int right){
    if(left >= right){
        return ;
    }

    //finding pivot index and arrange element according to pivot element 
    int p = partition(arr,left,right);

    // recurison calls 

    //for left 
    quickSort(arr,left,p-1);
    //for right
    quickSort(arr,p+1,right);
}

int main(){
    int arr[] = {55,4,26,22,7,9,65,9,9,5,2,2};
    int n = 12;
    int left = 0;
    quickSort(arr,left,n-1);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//Average case T.C. -> O(nlogn)
//worse case T.C.-> O(n^2)
//Space complexity -> O(n)

//or


#include <iostream>
#include <vector>
using namespace std;

int partition(int *arr, int left, int right)
{
    int pivot = arr[right];
    int i = left-1;
    int j = left;

    while (j<right)
    {
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }

    swap(arr[i+1],arr[j]);
    return i+1;
    

}

void quickSort(int *arr, int left, int right)
{

    if (left >= right)
    {
        return;
    }

    int p = partition(arr, left, right);

    quickSort(arr, left, p - 1);

    quickSort(arr, p + 1, right);
}

int main()
{
    int arr[] = {55, 4, 26, 22, 7, 9, 65, 9, 9, 5, 2, 2};
    int n = 12;
    int left = 0;
    int right = n - 1;

    quickSort(arr, left, right);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}