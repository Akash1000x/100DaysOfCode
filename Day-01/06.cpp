#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= (n - i + 1))
        {
            cout << j<<" ";
            j++;
        }
        // int star=i-1;
        // while(star>=1){
        //     cout<<"*";
        //     star--;
        // }

        // star=i-1;
        // while(star>=1){
        //     cout<<"*";
        //     star--;
        // }
        // j=j-1;
        // while(j>=1){
        //     cout<<j;
        //     j--;
        // }

        //or

       j=1;
       while(j<=(i-1)*2){
        cout<<"* ";
        j++;
       }

       j=n-i+1; 
       while(j>=1){
            cout<<j<<" ";
            j--;
       }


        cout << endl;
        i++;
    }
    return 0;
}