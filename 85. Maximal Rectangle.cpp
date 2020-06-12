//
// Created by homsl on 2020/2/10.
//
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty())
        return 0;
    vector<int> heights(matrix[0].size(), 0);
    int maxa = -1;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == '1')
                heights[j] += 1;
            else
                heights[j] = 0;
        }
        int area = largestRectangleArea(heights);
        maxa = max(maxa, area);
    }
    return maxa;
}

int largestRectangleArea(vector<int>& heights) {
    if(heights.empty())
        return 0;

    vector<int> stack;
    int index = 0;
    int area = 0;
    int maxr = -1;
    while(index < heights.size()){
        if(stack.empty() || heights[index] >= heights[stack.back()]){
            stack.push_back(index++);
        }
        else{
            int h = stack.back();
            stack.pop_back();
            if(stack.empty())
                area = heights[h]*index;
            else
                area = heights[h]*(index-stack.back()-1);
            maxr = max(maxr, area);
        }
    }
    while(!stack.empty()){
        int h = stack.back();
        stack.pop_back();
        if(stack.empty())
            area = heights[h]*index;
        else
            area = heights[h]*(index-stack.back()-1);
        maxr = max(maxr, area);
    }
    return maxr;
}
