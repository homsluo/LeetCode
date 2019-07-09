//
// Created by homsl on 2019/7/7.
//
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    int n = intervals.size();
    if(n < 2)
        return intervals;
    sort(intervals.begin(), intervals.end());
    int i = 1;
    for(; i < n; i++){
        if(intervals[i-1].back() >= intervals[i][0]){
            intervals[i].back() = max(intervals[i-1].back(), intervals[i].back());
            intervals[i][0] = intervals[i-1][0];
        }
        else
            ans.push_back(intervals[i-1]);
    }
    ans.push_back(intervals[i-1]);
    return ans;
}
