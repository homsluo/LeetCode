//
// Created by homsl on 2020/6/3.
//
class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Sort the differential between goes to A and goes to B
        // First compute the differents
        for(int i = 0; i < costs.size(); i++){
            costs[i].push_back(costs[i][1]-costs[i][0]);
        }
        sort(costs.begin(), costs.end(), compare);
        int res = 0;
        for(int i = 0; i < costs.size()/2; i++){
            res += costs[i][1];
        }
        for(int i = costs.size()/2; i < costs.size(); i++){
            res += costs[i][0];
        }
        return res;
    }
};

// Not modify the original vector
int twoCitySchedCost(vector<vector<int>>& costs) {
    // Sort the differential between goes to A and goes to B
    priority_queue<pair<int, int>> pq;
    int n = costs.size();
    for(int i = 0; i < n; i++){
        pq.push({(costs[i][1]-costs[i][0]), i});
    }
    int res = 0;
    for(int i = 0; i < n/2; i++){
        res += costs[pq.top().second][0];
        pq.pop();
    }
    for(int i = n/2; i < n; i++){
        res += costs[pq.top().second][1];
        pq.pop();
    }
    return res;
}
