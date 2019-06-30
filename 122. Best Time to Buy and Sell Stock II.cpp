//
// Created by homsl on 2019/6/19.
//
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)
        return 0;
    int ans = 0;
    for(int i = 1; i < prices.size(); i++)
        if(prices[i] > prices[i-1])
            ans += prices[i]-prices[i-1];
    return ans;
}
