#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom1(stack<int> &s, int &target)
{
    //base case
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    // recursive call
    insertAtBottom1(s, target);

    // backtrack
    s.push(temp);
}

void Reverse(stack<int> &St)
{
    //base case
    if (St.empty())
    {
        return;
    }

    int target = St.top();
    St.pop();

    //recursive call
    Reverse(St);

    //insert at bottom target ko
    insertAtBottom1(St, target);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    Reverse(s);

    cout << "After Reverse:" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}