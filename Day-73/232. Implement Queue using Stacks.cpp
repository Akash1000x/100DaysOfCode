class MyQueue {
public:
stack<int> s,i;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s.empty()){
            i.push(s.top());
            s.pop();
        }

        s.push(x);

        while(!i.empty()){
            s.push(i.top());
            i.pop();
        }
    }
    
    int pop() {
        int n = s.top();
        s.pop();
        return n;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
       if(s.empty()){
            return true;
        }
        else{
            return false;
        } 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */







//or 





class MyQueue {
public:
stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }  
      
        int element = s2.top();
        s2.pop();
        return element;
    }
    
    int peek() {
         if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }    
        int element = s2.top();
        return element;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */