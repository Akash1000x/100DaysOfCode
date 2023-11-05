class MyStack {
public:
queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i = 0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


//or


class MyStack {
public:
queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int element = q1.front();
        q1.pop();
        return element;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */