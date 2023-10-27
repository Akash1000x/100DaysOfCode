class Solution {
    class Car{//creating a class for tracking position w.r.t. speed 
        public:
        int pos,speed;
        Car(int p,int s):pos(p),speed(s){};
    };

    static bool myComp(Car &a,Car &b){
        return a.pos < b.pos;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<Car> cars;

        for(int i =0;i<position.size();i++){
            Car car(position[i],speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(),cars.end(),myComp);
        

        stack<float> arrivalTimes;

        for(auto car:cars){

            float time = (target-car.pos)/(float)car.speed;

            while(!arrivalTimes.empty() && arrivalTimes.top() <= time){
                arrivalTimes.pop();
            }
            arrivalTimes.push(time);
        }
        return arrivalTimes.size();
    }
};


//or

// class Solution {
// public:
//     int carFleet(int target, vector<int>& position, vector<int>& speed) {
//         vector<pair<int,int>> v;

//         for(int i= 0;i<position.size();i++){
//             v.push_back({position[i],speed[i]});
//         }
//         sort(v.begin(),v.end());

//         stack<float> st;

//         for(int i = 0;i<v.size();i++){
//             float time = (target-v[i].first)/(float)v[i].second;
            
//             while(!st.empty() && st.top() <= time){
//                 st.pop();
//             }
//             st.push(time);
//         }
//         return st.size();
//     }
// };