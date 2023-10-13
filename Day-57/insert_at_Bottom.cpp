#include<iostream>
#include<stack>
using namespace std;

void insertElement(stack<int> &s,int &element){

    

    //base case
    if(s.empty()){
        s.push(element);
        return;
    }

    int temp = s.top();
    s.pop();

    //recursive call
    insertElement(s,element);

    //backtrack
    s.push(temp);

    
    

}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    //stack is empty
    if(s.empty()){
        cout<<"stack is empty"<<endl;
        return 0; 
    }


    int element = s.top();
    s.pop();

    insertElement(s,element);

    //Printing
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}