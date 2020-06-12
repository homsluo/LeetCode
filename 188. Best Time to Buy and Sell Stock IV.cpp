//
// Created by homsl on 2020/5/5.
//
int maxProfit(int k, vector<int>& prices) {
    if(prices.empty())
        return 0;
    int n = prices.size();
    vector<vector<int>> local(k+1, vector<int>(n, 0));
    vector<vector<int>> global(k+1, vector<int>(n, 0));

    for(int i = 1; i <= k; i++){
        for(int j = 1; j < n; j++){
            int diff = prices[j]-prices[j-1];
            local[i][j] = max(0, max(local[i][j-1], global[i-1][j-1]))+diff;
            global[i][j] = max(global[i][j-1], local[i][j]);
        }
    }
    return global[k][n-1];
}
// -------------------------------------------------------------
// Time: O(nk), Space: O(nk)
int maxProfit(int k, vector<int>& prices) {
    if(prices.empty())
        return 0;
    int n = prices.size();
    vector<vector<int>> profit(k+1, vector<int>(n, 0));
    for(int t = 1; t <= k; t++){
        int prepro = INT32_MIN;
        for(int d = 1; d < n; d++){
            prepro = max(prepro, profit[t-1][d-1]-prices[d-1]);
            profit[t][d] = max(profit[t][d-1], prices[d] + prepro);
        }
    }
    return profit[k][n-1];
}
// --------------------------------------------------------------------
// Time: O(nk), Space: O(n)
int maxProfit(int k, vector<int>& prices) {
    if(prices.empty())
        return 0;
    int n = prices.size();
    vector<vector<int>> profit(2, vector<int>(n, 0));
    int cur, pre;
    for(int t = 1; t <= k; t++){
        int prepro = INT32_MIN;
        if(t%2){
            int cur = 1;
            int pre = 0;
        }
        else{
            int cur = 0;
            int pre = 1;
        }
        for(int d = 1; d < n; d++){
            prepro = max(prepro, profit[pre][d-1] - prices[d-1]);
            profit[cur][d] = max(profit[cur][d-1], prices[d] + prepro);
        }
    }
    return (k%2 == 1)?profit[1][n-1]:profit[0][n-1];
}
