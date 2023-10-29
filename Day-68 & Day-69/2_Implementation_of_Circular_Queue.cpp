#include<iostream>
#include<vector>
using namespace std;

class Cqueue{
    int *arr;
    int size,front,rear;
    public:
    //constructor
    Cqueue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    //push function
    void push(int data){
        if((front == 0 && rear == size-1) || (front == rear+1)){
            cout<<"Queue is full"<<endl;
        }
        //no element in queue
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        // make circular nature
        else if(rear == size-1 && front != 0 ){
            rear = 0;
            arr[rear] = data;
        }
        ///normal flow
        else{
            rear++;
            arr[rear] = data;
        }
    }

    //pop function
    void pop(){
        if(front == -1 && rear == -1){
            cout<< "Queue is empty"<<endl;
        }
        //single element
        else if(front == rear){
            front = rear = -1;
        }
        //circular nature
        else if(front == size-1 ){
            front = 0;
        }
        ///normal flow
        else{
            front++;
        }
    }

    //get front function
    int getfront(){
        if(front == -1 && rear == -1){
            cout<< "Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }


    //check empty or not 
    bool isempty(){
        if(front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }
    }

    // Get the size of the queue
    int getsize() {
        if (front == -1 && rear == -1) {
            return 0;
        } else if(front > rear){
            return size-front + rear+1;
        }
        else{
            return rear - front + 1;
        }
    }

};

int main(){
    Cqueue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);


    cout<<q.getfront()<<endl;
    q.pop();
    cout<<q.getfront()<<endl;

    q.push(60);
    q.push(70);

    cout<<q.getfront()<<endl;

    cout<<"Size of the circular Queue:"<<q.getsize()<<endl;


    return 0;
}