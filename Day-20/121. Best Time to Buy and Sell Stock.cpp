class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int miniprice = INT_MAX;
        int maximumProfit = 0;
        for(int i = 0;i<n;i++){
            if(prices[i] < miniprice){
                miniprice = prices[i];
            }
            else if(prices[i]-miniprice > maximumProfit ){
                maximumProfit =prices[i]-miniprice;
            }
        }
        return maximumProfit;
    }
};