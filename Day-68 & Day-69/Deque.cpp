#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;

    dq.push_front(5);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(8);
    dq.push_front(10);

    cout<<"front:"<<dq.front()<<endl;

    cout<<"back"<<dq.back()<<endl;

    cout<<"size"<<dq.size()<<endl;

    dq.pop_front();
    cout<<"size"<<dq.size()<<endl;

    dq.pop_back();
    cout<<"size"<<dq.size()<<endl;

    cout<<"front:"<<dq.front()<<endl;

    cout<<"back"<<dq.back()<<endl;



    return 0;
}