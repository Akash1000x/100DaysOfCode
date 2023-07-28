#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        // int j=n;
        // while(j>=1){
        //    if(i>=j){
        //     cout<<"* ";
        //    }
        //    else{
        //     cout<<" ";
        //    }
        //    j--;
        // }

       int j=1;
       while(j<=n-i+1){
        cout<<" ";
        j++;
       } 
       j=1;
       while(j<=i){
        cout<<"* ";
        j++;
       }

        cout<<endl;
        i++;
    }
    return 0;
}