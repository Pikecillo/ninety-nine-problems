class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int min = prices.front();
        int max_profit = 0;
        
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min)
                min = prices[i];
                
            if(prices[i] - min > max_profit) {
                max_profit = prices[i] - min;
            }
        }
        
        return max_profit;
    }
};

