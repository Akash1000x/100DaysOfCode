#include <iostream>
#include <stack>
using namespace std;

// using recursion
stack<int> insertAtBottom1(stack<int> &s, int &target)
{

    // if(s.empty()){
    //     s.push(target);
    //     return s;
    // }

    // int temp = s.top();
    // s.pop();

    // //recursive call
    // insertAtBottom(s,target);

    // //backtrack
    // s.push(temp);

    // return s;

    // or

    if (s.empty())
    {
        s.push(target);
    }

    else
    {
        int temp = s.top();
        s.pop();

        // recursive call
        insertAtBottom1(s, target);

        // backtrack
        s.push(temp);
    }

    return s;
}

// using loops
stack<int> insertAtBottom2(stack<int> &S, int &target)
{
    // create a new stack
    stack<int> st;
    
    //push values to new stack(st)
    while (!S.empty())
    {
        st.push(S.top());
        S.pop();
    }
    //at bottom push target value
    st.push(target);

    //push values in old stack(S)
    while (!st.empty())
    {
        S.push(st.top());
        st.pop();
    }

    return S;
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int target = 60;
    insertAtBottom2(s, target);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}