//
// Created by homsl on 2020/2/6.
//
// O(n^2)
int largestRectangleArea(vector<int>& heights) {
    if(heights.empty())
        return 0;
    if(heights.size() == 1)
        return heights[0];
    int maxr = 0;
    for(int i = 0; i < heights.size(); i++){
        if(i == heights.size()-1 || heights[i] > heights[i+1]){
            int minh = heights[i];
            for(int j = i; j >= 0; j--){
                minh = min(heights[j], minh);
                maxr = max((i-j+1)*minh, maxr);
            }
        }
    }
    return maxr;
}

// O(n)
int largestRectangleArea(vector<int>& heights) {
    if(heights.empty())
        return 0;
    if(heights.size() == 1)
        return heights[0];

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
