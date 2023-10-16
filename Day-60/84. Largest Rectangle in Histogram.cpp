class Solution {
    // Helper function to find the previous smaller element's index for each element
    vector<int> prevSmaller(vector<int>& heights, int &n) {
        vector<int> prev(n); // Initialize a vector to store previous smaller indices
        stack<int> st;
        st.push(-1); 

        for (int i = 0; i < n; i++) {
            int curr = heights[i];
            while (st.top() != -1 && heights[st.top()] >= curr) {
                st.pop(); // Pop elements from the stack until we find a smaller element
            }
            prev[i] = st.top(); // Store the index of the previous smaller element
            st.push(i); // Push the current index onto the stack
        }
        return prev; // Return the vector containing previous smaller indices
    }

    // Helper function to find the next smaller element's index for each element
    vector<int> nextSmaller(vector<int> &heights, int &n) {
        vector<int> next(n); // Initialize a vector to store next smaller indices
        stack<int> st;
        st.push(-1); // Push a sentinel value -1 onto the stack

        for (int i = n - 1; i >= 0; i--) {
            int curr = heights[i];
            while (st.top() != -1 && heights[st.top()] >= curr) {
                st.pop(); // Pop elements from the stack until we find a smaller element
            }
            next[i] = st.top(); // Store the index of the next smaller element
            st.push(i); // Push the current index onto the stack
        }
        return next; // Return the vector containing next smaller indices
    }

public:
    // Main function to calculate the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();

        // Calculate previous smaller and next smaller indices for each element
        vector<int> prev = prevSmaller(heights, n);
        vector<int> next = nextSmaller(heights, n);

        for (int i = 0; i < n; i++) {
            int height = heights[i];

            // If there is no next smaller element, set it to the end of the array
            if (next[i] == -1) {
                next[i] = n;
            }

            int width = next[i] - prev[i] - 1; // Calculate the width of the rectangle
            int area = width * height; // Calculate the area of the rectangle

            maxArea = max(maxArea, area); // Update the maximum area if needed
        }

        return maxArea; // Return the maximum area
    }
};
