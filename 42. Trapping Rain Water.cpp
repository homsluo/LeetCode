//
// Created by homsl on 2020/1/15.
//

int trap(vector<int>& height) {
    int leftmost = 0, rightmost = 0;
    int i = 0, j = height.size()-1;
    int water = 0;
    while(i < j){
        leftmost = max(leftmost, height[i]);
        rightmost = max(rightmost, height[j]);
        if(leftmost > rightmost){
            water += rightmost-height[j];
            j--;
        }
        else{
            water += leftmost-height[i];
            i++;
        }
    }
    return water;
}