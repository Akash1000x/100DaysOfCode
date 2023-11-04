#include <iostream>
#include <vector>
using namespace std;

class N_queue
{
    int *arr, *front, *rear, *next;
    int size, freespot, k;

public:
    N_queue(int size, int k)
    {
        this->size = size;
        this->k = k;
        freespot = 0;
        arr = new int[size];
        front = new int[k];
        rear = new int[k];
        next = new int[size];

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
    }

    // push x in mth queue
    bool push(int x, int m)
    {
        // overflow
        if (freespot == -1)
        {
            cout << "q is full" << endl;
            return false;
        }
        // find first free index
        int index = freespot;
        // update freespot
        freespot = next[index];
        // first element in queue
        if (front[m - 1] == -1)
        {
            front[m - 1] = index;
        }

        else
        {
            // link new element to q's rearest element
            next[rear[m - 1]] = index;
        }
        // update next
        next[index] = -1;
        // update rear
        rear[m - 1] = index;

        arr[index] = x;

        return true;
    }

    // pop element from qith queue
    int pop(int qn)
    {
        // underflow
        if (front[qn - 1] == -1)
        {
            cout << "Q is empty" << endl;
            return -1;
        }
        // find the indes to pop
        int index = front[qn - 1];
        // front update
        front[qn - 1] = next[index];
        // update freespots
        next[index] = freespot;

        // update freespot
        freespot = index;

        return arr[index];
    }

    ~N_queue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main()
{
    N_queue q(8, 3);

    cout << q.push(2, 1) << endl;
    cout << q.push(8, 1) << endl;
    cout << q.push(5, 2) << endl;
    cout << q.push(4, 3) << endl;
    cout << q.pop(1) << endl;
    cout << q.pop(2) << endl;

    return 0;
}