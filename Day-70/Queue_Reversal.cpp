#include<iostream>
#include<queue>
using namespace std;

//reverse queue
void reverse(queue<int> &q){
    if(q.empty()){
        return;
    }

    int target = q.front();
    q.pop();

    //recursive call
    reverse(q);

    //last step
    q.push(target);
}

int main(){

    queue<int> q;
    q.push(5);
    q.push(7);
    q.push(9);
    q.push(4);

    reverse(q);
    //reversed queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}