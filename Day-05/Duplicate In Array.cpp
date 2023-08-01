int findDuplicate(vector<int> &arr) 
{   
       
        int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        ans =arr[i]^ans;
    }
    for(int i = 1; i<arr.size();i++){
        ans=ans^i;
    }
    return ans;
}
