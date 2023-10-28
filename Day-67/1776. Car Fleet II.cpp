class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {

        //collusion time of ith car array
        vector<double> time(cars.size(),-1);
        stack<int> st;

        //traverse from last car to first car
        for(int i = cars.size()-1; i >= 0 ; i--){
            
            //if current car is slower than the car in stack(next car)
            while(!st.empty() && cars[i][1] <= cars[st.top()][1]){
                st.pop();
            }

            
            while(!st.empty()){
                //collision time of ith car with next car
                double colTime = (double)(cars[st.top()][0]-cars[i][0] )/(cars[i][1]-cars[st.top()][1] );
                if(time[st.top()] == -1 || time[st.top()] >= colTime){
                    time[i] = colTime;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return time;
    }
};