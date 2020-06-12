//
// Created by homsl on 2020/3/4.
//
int maxProfit(vector<int>& prices) {
    if(prices.empty())
        return 0;
    int buy1 = INT32_MAX;
    int buy2 = INT32_MAX;
    int sell1 = 0;
    int sell2 = 0;
    for(int i = 0; i < prices.size(); i++){
        sell1 = max(sell1, prices[i] - buy1);
        buy1 = min(buy1, prices[i]);
        sell2 = max(sell2, prices[i] - buy2);
        buy2 = min(buy2, prices[i] - sell1);
    }
    return sell2;
}
//-----------------------------------------------

int maxProfit(vector<int>& prices) {
    if(prices.empty())
        return 0;

    vector<int> profitleft(prices.size(), 0);
    int pricelow = prices[0];
    for(int i = 1; i < prices.size(); i++){
        profitleft[i] = max(profitleft[i-1], prices[i] - pricelow);
        pricelow = min(pricelow, prices[i]);
    }

    vector<int> profitright(prices.size(), 0);
    int pricehigh = prices.back();
    for(int i = prices.size()-2; i >= 0; i--){
        profitright[i] = max(profitright[i+1], pricehigh - prices[i]);
        pricehigh = max(pricehigh, prices[i]);
    }

    int res = 0;
    for(int i = 0; i < prices.size(); i++){
        res = max(res, profitleft[i] + profitright[i]);
    }
    return res;
}
