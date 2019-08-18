//
// Created by homsl on 2019/7/27.
//
int minimumTotal(vector<vector<int>>& triangle) {
    if(!triangle.size())
        return 0;
    vector<int> sum(triangle.size(), 0);
    sum[0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++){
        sum[i] = sum[i-1] + triangle[i][i];
        if(i > 1){
            for(int j = i-1; j > 0; j--){
                sum[j] = min(sum[j-1], sum[j]) + triangle[i][j];
            }
        }
        sum[0] += triangle[i][0];
    }
    sort(sum.begin(), sum.end());
    return sum[0];
}
