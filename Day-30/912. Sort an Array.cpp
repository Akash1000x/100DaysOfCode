class Solution {
public:

void merge(vector<int>& arr,int start,int end){

    int mid = (start+end)/2;
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
        if(arr1[index1] < arr2[index2]){
            arr[mainIndex++] = arr1[index1++];
        }
        else{
            arr[mainIndex++] = arr2[index2++];
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
}



//Recurison function
void mergSort(vector<int>& arr,int start,int end){

    if(start>=end){
        return;
    }

    int mid = (start+end)/2;

    //sorting left half of array
    mergSort(arr,start,mid);

    //sorting right half of array
    mergSort(arr,mid+1,end);

    //merge sorted array
    merge(arr,start,end);


}
    vector<int> sortArray(vector<int>& nums) {

        mergSort(nums,0,nums.size()-1);


        return nums;
    }
};