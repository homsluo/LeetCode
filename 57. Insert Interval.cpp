//
// Created by homsl on 2020/1/28.
//
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if(intervals.empty()){
        intervals.push_back(newInterval);
        return intervals;
    }
    vector<vector<int>> res;
    int i = 0;
    int n = intervals.size();
    int left = newInterval[0];
    int right = newInterval[1];
    // Find Start
    while(i < n && intervals[i][1] < left){
        res.push_back(intervals[i]);
        i++;
    }
    // If newInterval is the last one
    if(i == n){
        res.push_back(newInterval);
        return res;
    }
    left = min(left, intervals[i][0]);

    //Find End
    while(i < n && intervals[i][0] <= right){
        right = max(right, intervals[i][1]);
        i++;
    }
    res.push_back({left,right});
    while(i < n){
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}
