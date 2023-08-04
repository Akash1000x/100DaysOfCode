long long int floorSqrt(long long int N)
{   
    if(N==0 || N==1){
        return N;
    }
    unsigned long long int result = 1;
    int ans =-1;
    long long int s = 0;
    long long int e = N-1;
    unsigned long long int mid = s + (e-s)/2;
    while(s<=e){
        result = mid*mid;
        if(result == N){
            ans =mid;
        }
         if(result < N){
            ans = mid;
            s = mid +1;
        }
        else{
            e = mid -1;
        }
        mid = s + (e-s)/2;
    }
    return mid ;
}