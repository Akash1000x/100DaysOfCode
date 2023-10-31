#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q,int k){

    if(k <= 0 || k > q.size()){
        cout << "Invalid value of K" << endl;
        return;
    }
    stack<int> st;

    // Pop elements from the stack and enqueue them to the queue
    for(int i = 0;i<k;i++){
        st.push(q.front());
        q.pop();

    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();

    }


    //push first n-k element in (last of)queue      
    for(int i =0;i<q.size()-k;i++){

        q.push(q.front());
        q.pop();

    }
}

int main(){

    queue<int> q;
    int k = 3;
    q.push(5);
    q.push(7);
    q.push(9);
    q.push(4);
    q.push(6);


    reverseQueue(q,k);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}