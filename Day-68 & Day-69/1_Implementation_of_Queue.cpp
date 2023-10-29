#include <iostream>
using namespace std;

class Queue
{
    int size, front, rear;
    int *arr;

public:
    //constructor
    Queue(int _s):size(_s)
    {
        arr = new int[size];
        // this->size = size;
        front = 0;
        rear = 0;
    }

    //push function
    void push(int data)
    {
        if (rear >= size)//check array is full or not
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    //pop function;
    void pop()
    {
        if (front == rear)//check empty
        {
            cout << "Queue is empty" << endl;
        }
        else
        {   
            // cout<<"removing front item :"<<arr[front]<<endl;
            front++;
            if (front == rear)//if entire queue is empty  
            {   
                front = 0;
                rear = 0;
            }
        }
    }
    // getFront function
    int getfront()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    
    int getsize(){
        return rear - front;
    }

    bool isempty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Queue q(6);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Getting front element
    cout <<"front element of queue:"<< q.getfront() << endl;
    //removel
    
    q.pop();
    cout << "front element of queue:"<<q.getfront() << endl;

    //get size;
    cout<<"size of the queue is:"<<q.getsize()<<endl;

    // Checking empty 
    if (q.isempty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}