class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //kitna gas bacha hua h
        int balance = 0;
        //circuit kha se start kr rahe h
        int index = 0;
        //kitna gas kam padega
        int deficit = 0;

        for(int i = 0;i<gas.size();i++){
            balance += gas[i] - cost[i]; // Calculate the remaining gas after traveling to the next station

            if (balance < 0) {
                deficit += balance;  // If balance goes negative, accumulate the deficit
                index = i + 1;       // Update the starting index to the next station
                balance = 0;         // Reset the balance to zero
            }
        }

        if(balance + deficit >= 0){
            return index;
        }
        else{
            return -1;
        }
    }
};