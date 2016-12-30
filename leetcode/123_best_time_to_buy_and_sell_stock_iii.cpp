class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        
        const int size = prices.size();
        vector<int> first(size, 0);
        vector<int> second(size, 0);
        
        int min = prices.front();
        for(int i = 1; i < size; i++) {
            if(prices[i] < min)
                min = prices[i];
                
            if(prices[i] - min > first[i - 1])
                first[i] = prices[i] - min;
            else
                first[i] = first[i - 1];
        }
        
        int max = prices.back();
        for(int i = size - 2; i >= 0; i--) {
            if(prices[i] > max)
                max = prices[i];
                
            if(max - prices[i] > second[i + 1])
                second[i] = max - prices[i];
            else
                second[i] = second[i + 1];
        }
        
        int max_profit = first.back();
        for(int i = 0; i < size - 1; i++) {
            if(first[i] + second[i + 1] > max_profit)
                max_profit = first[i] + second[i + 1];
        }
        
        return max_profit;
    }
};
