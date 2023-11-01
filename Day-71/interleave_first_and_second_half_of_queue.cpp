#include<iostream>
#include<queue>
using namespace std;

void interleaveQueue(queue<int> &q){

    if(q.empty()){
        return;
    }
    int n = q.size();
    int k = n/2;
    queue<int> temp;

    //push half element into new temp queue
    for(int i =0;i<k;i++){
        temp.push(q.front());
        q.pop();
    }

    //interleave 
    for(int i = 0;i<k;i++){
        q.push(temp.front());
        temp.pop();

        q.push(q.front());
        q.pop();
    }

    //if size of queue is odd
    if(n&1){
        q.push(q.front());
        q.pop();
    }
}



int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    interleaveQueue(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}