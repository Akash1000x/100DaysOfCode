
#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &s, int &target)
{
    //base case
    if (s.empty())
    {
        s.push(target);
        return;
    }


    if(target <= s.top()){
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    // recursive call
    insertSorted(s, target);

    // backtrack
    s.push(temp);
}

void sortStack(stack<int> &St)
{
    //base case
    if (St.empty())
    {
        return;
    }

    int target = St.top();
    St.pop();

    //recursive call
    sortStack(St);

    //insert at bottom target ko
    insertSorted(St, target);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(5);
    s.push(3);
    s.push(2);
    s.push(8);

    sortStack(s);

    cout << "After sort:" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}