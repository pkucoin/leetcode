class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0)
            return 0;
        int curMin = prices[0];
        int profit = 0;
        int len = prices.size();
        int i;
        for (i = 1;i < len;i++)
        {
            if (prices[i-1] < curMin)
            {
                curMin = prices[i-1];
            }
            
            if (prices[i] - curMin > profit)
            {
                profit = prices[i] - curMin;
            }
        }
        
        return profit;
    }
};