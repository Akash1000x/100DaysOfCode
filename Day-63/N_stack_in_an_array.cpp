#include <iostream>
#include <vector>
using namespace std;

class N_stack
{
    int *arr, *top, *next;
    int n;        // number of stacks
    int size;     // size of array
    int freeSpot; // tells free space in array
public:
    N_stack(int _n,int _s):n(_n),size(_s)
    {
        freeSpot = 0;
        arr = new int[size];
        top = new int[n];
        next = new int[size];

        for(int i = 0;i<n;i++){
            top[i] = -1;
        }

        for(int i = 0;i<size;i++){
            next[i] = i+1;
        }
        next[size-1] = -1;

    }

    //push x into mth stack.( m vi stack me x dal do )
    bool push(int x, int m){

        if(freeSpot == -1){
            return false;//stack overflow
        }
        //find index
        int index = freeSpot;
        
        //update freespot
        freeSpot = next[index];

        //insert 
        arr[index] = x;

        //update next
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;
    }

    //pop into mth stack.
    int pop(int m){
        if(top[m-1] == -1){
            return -1;//stack underflow
        }
        //find index
        int index = top[m-1];

        //update top
        top[m-1] = next[index];
        //pop
        int popedelement = arr[index];

        //update next
        next[index] = freeSpot;
        //update freespot
        freeSpot = index;

        return popedelement;//return poped element
    }

    ~N_stack(){
        delete[] arr;
        delete[] top;
        delete[] next;
    }

};


int main(){
    N_stack s(3,6);
    cout<<s.push(10,1)<<endl;
    cout<<s.push(20,1)<<endl;
    cout<<s.push(150,2)<<endl;
    cout<<s.push(30,1)<<endl;
    cout<<s.push(12,3)<<endl;
    cout<<s.push(15,1)<<endl;
    cout<<s.pop(3)<<endl;
    cout<<s.pop(3)<<endl;

    return 0;
}