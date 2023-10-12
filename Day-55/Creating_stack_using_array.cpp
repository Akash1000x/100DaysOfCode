#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data)
    {
        if (top + 1 >= size)
        {
            cout << "Stack is Overflow, so can not push element" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }

        // or

        // if(size-top > 1){
        //     top++;
        //     arr[top] = data;
        // }
        // else{
        //     cout << "Stack is Overflow, so can not push element"<<endl;
        // }
    }

    void pop()
    {
        if (top == -1)
        {
            // stack is empty
            cout << "Stack underflow, can't delete" << endl;
        }
        else
        {

            // stack is not empty
            top--;
        }
    }

    int getTop()
    {
        // whene stack is empty
        if (top == -1)
        {
            cout << "There is no element in stack" << endl;
        }
        else
        {
            return arr[top];
        }
    }

    int getSize()
    {
        return top + 1;
    }

    bool isempty()
    {
        if (top == -1)
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
    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Size:" << s.getSize() << endl;

    while (!s.isempty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;

    s.pop();

    return 0;
}