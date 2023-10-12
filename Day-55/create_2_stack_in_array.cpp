#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "Stack is Overflow, so can not push element" << endl;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            // stack is empty
            cout << "Stack underflow, can't delete" << endl;
        }
        else
        {

            // stack is not empty
            arr[top1] = 0;
            top1--;
        }
    }

    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "Stack is Overflow, so can not push element" << endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }

    void pop2()
    {
        if (top2 == size)
        {
            // stack is empty
            cout << "Stack underflow, can't delete" << endl;
        }
        else
        {

            // stack is not empty
            arr[top2] = 0;
            top2++;
        }
    }

    // samjane ke lia only
    // void print(){
    //     cout<<endl;
    //     cout<<"top1:"<<top1<<endl;
    //     cout<<"top2:"<<top2<<endl;
    //     for(int i = 0;i<size;i++){
    //         cout<<arr[i]<<" ";
    //     }cout<<endl;
    // }
};

int main()
{
    Stack s(10);

    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push1(50);

    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push2(40);
    s.push2(50);

    s.pop2();
    s.pop2();
    s.pop2();

    s.push2(198);
    return 0;
}