//
// Created by homsl on 2019/7/6.
//
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if(matrix.size() == 0)
        return ans;
    if(matrix.size() == 1)
        return matrix[0];
    int wid = matrix[0].size();
    int height = matrix.size();
    int nums = wid*height;
    int i = 0, j = 0;
    height--;
    while(ans.size() != nums){
        for(int k = 0; k < wid; k++, j++)
            ans.push_back(matrix[i][j]);
        if(ans.size() == nums)
            return ans;
        j--;
        wid--;
        i++;
        for(int k = 0; k < height; k++, i++)
            ans.push_back(matrix[i][j]);
        if(ans.size() == nums)
            return ans;
        i--;
        height--;
        j--;
        for(int k = 0; k < wid ; k++, j--)
            ans.push_back(matrix[i][j]);
        if(ans.size() == nums)
            return ans;
        j++;
        wid--;
        i--;
        for(int k = 0; k < height; k++, i--)
            ans.push_back(matrix[i][j]);
        if(ans.size() == nums)
            return ans;
        i++;
        height--;
        j++;

    }
    return ans;
}
