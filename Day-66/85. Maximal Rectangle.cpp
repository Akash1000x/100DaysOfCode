class Solution {
     vector<int> nextSmaller(vector<int>& v){
        vector<int> next(v.size());
        stack<int> st;
        st.push(-1);

        for(int i=v.size()-1;i>=0;i--){
            while(st.top() != -1 && v[st.top()] >= v[i] ){
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
        return next;
    }

    vector<int> prevSmaller(vector<int>& v){
        vector<int> prev(v.size());
        stack<int> st;
        st.push(-1);
        for(int i=0;i<v.size();i++){
            while(st.top() != -1 && v[st.top()] >= v[i] ){
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
        return prev;
    }
    //84. Largest Rectangle in Histogram
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> next = nextSmaller(heights);
        vector<int> prev = prevSmaller(heights);

        int maxarea = 0;
        for(int i = 0; i<heights.size(); i++){
            int height = heights[i];

            if(next[i] == -1){
                next[i] = heights.size();
            }

            int width = next[i] - prev[i] -1;
            int area = height*width;

            maxarea = max(maxarea,area);

        }

        return maxarea;    
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // vector<vector<int>> v;

        // for(int i = 0;i<matrix.size();i++){
        //     vector<int> temp;
        //     for(int j= 0;j<matrix[0].size();j++){
        //         temp.push_back(matrix[i][j] -'0');
        //     }
        //     v.push_back(temp);
        // }

        // int maxArea = largestRectangleArea(v[0]);

        // for(int i = 1;i<matrix.size();i++){
        //     for(int j= 0;j<matrix[0].size();j++){
        //         if(v[i][j] == 1){
        //             v[i][j] += v[i-1][j];
        //         }
        //         else{
        //             v[i][j] =0;
        //         }

        //     }
        //     maxArea = max(maxArea,largestRectangleArea(v[i]));
        // }
    
        // return maxArea;
        
        
        int col = matrix[0].size();
        //make a histogram of each row
        vector<int> height(col, 0);
        
        int maxArea = 0;

        for(int i = 0;i<matrix.size();i++){//row
            for(int j= 0;j<matrix[0].size();j++){//col

                if(matrix[i][j] == '1'){
                    height[j]++; //add 1 to the height of the histogram
                }
                //if the current element is 0, then the height of the histogram is 0
                else height[j] = 0;

            }
            maxArea = max(maxArea,largestRectangleArea(height));
        }
        return maxArea;
        
    }
}; 