class MinStack {
public:
    vector<pair<int, int>> st; // A vector of pairs to store values and corresponding minimums

    MinStack() {
    }

    // Push a new value onto the stack
    void push(int val) {
        if (st.empty()) {
            // If the stack is empty, add the first pair with the value as both the value and the minimum.
            st.push_back(make_pair(val, val));
        } else {
            // If the stack is not empty, calculate the minimum between the current value and the previous minimum.
            int mini = min(val, st.back().second);

            // Add the pair with the value and the calculated minimum to the stack.
            st.push_back(make_pair(val, mini));
        }
    }

    // Pop the top element from the stack
    void pop() {
        st.pop_back();
    }

    // Get the top value of the stack
    int top() {
        return st.back().first;
    }

    // Get the minimum value in the stack
    int getMin() {
        return st.back().second;
    }
};



//other approach using two stack

 class MinStack {
public:
    stack<int> st;  // Stack to store the values
    stack<int> minSt;  // Stack to store the minimum values

    MinStack() {
    }

    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (!st.empty()) {
            if (st.top() == minSt.top()) {
                minSt.pop();
            }
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
