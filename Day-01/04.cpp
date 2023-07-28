#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            if((i-1)>=j){
                cout<<" ";
            }
            else{
                cout<<j;
            }
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}