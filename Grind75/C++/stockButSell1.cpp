class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0, minimumPrice = INT_MAX;
        for (const auto& price : prices) {
            minimumPrice = min(minimumPrice, price);
            maximumProfit = max(maximumProfit, price - minimumPrice);
        }
        return maximumProfit;
    }
};