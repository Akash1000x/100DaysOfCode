#include<iostream>
#include<vector>
using namespace std;

void PermutationOfString(string &s,int n,int i){
    if(i>=n){
        cout<<s<<endl;
        return;
    }

    //swaping
    for(int j = i;j<n;j++){
        //swap
        swap(s[i],s[j]);

        //recurision call
        PermutationOfString(s,n,i+1);

        //backtracking
        swap(s[i],s[j]);
    }
}

int main(){
    string s  = "abc";
    int n = s.size();
    PermutationOfString(s,n,0);
    return 0;
}

//Time complexity  -> O(n!)
//Space complexity -> O(n) 