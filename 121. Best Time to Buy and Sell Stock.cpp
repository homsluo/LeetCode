//
// Created by homsl on 2019/6/19.
//
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)
        return 0;
    int min_v = prices[0], ans = 0;
    for(int j = 1; j < prices.size(); j++){
        if(prices[j] > min_v)
            ans = max(ans, prices[j] - min_v);
        else if(prices[j] < min_v)
            min_v = prices[j];
    }
    return ans;
}
