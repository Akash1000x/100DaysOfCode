class Solution {
public:
    vector<double> convertTemperature(double celsius) {

        double kelvin = celsius+273.15;
        double Fahranheit = celsius * 1.80 +32.00;

        vector<double> ans{kelvin,Fahranheit};

        return ans;
    }
};