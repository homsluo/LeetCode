//
// Created by homsl on 2020/4/1.
//
int maxPoints(vector<vector<int>>& points) {
    if(points.size() <= 2)
        return points.size();

    int ans = 2;
    for(int i = 0; i < points.size(); i++){
        map<pair<int, int>, int> slope_count;
        pair<int, int> point_i = {points[i][0], points[i][1]};
        int max_p = 0;
        int dup_p = 1;
        for(int j = i+1; j < points.size(); j++){
            pair<int, int> point_j = {points[j][0], points[j][1]};
            if(point_i == point_j)
                dup_p++;
            else
                max_p = max(max_p, ++slope_count[getslope(point_i, point_j)]);
        }
        ans = max(ans, max_p+dup_p);
    }
    return ans;
}

pair<int, int> getslope(pair<int, int>& p1, pair<int, int>& p2){
    int dx = p1.first-p2.first;
    int dy = p1.second-p2.second;
    if(!dx)
        return {p1.first, 0};
    if(!dy)
        return {0, p1.second};
    const int d = gcd(dx, dy);
    return {dx/d, dy/d};
}

int gcd(int m, int n){
    return n == 0? m : gcd(n, m % n);
}
