//
// Created by homsl on 2019/6/24.
//
int maxArea(vector<int>& height) {    // Quick Sort idea
    int i = 0, j = height.size()-1;
    int maxarea = (j-i) * min(height[i], height[j]);
    while(i < j){
        if(height[i] < height[j])
            i++;
        else
            j--;
        maxarea = max(maxarea, min(height[i],height[j])*(j-i));
    }
    return maxarea;
}
