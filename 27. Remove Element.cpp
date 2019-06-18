//
// Created by homsl on 2019/6/16.
//
#include <iostream>
#include <vector>
using namespace std;
#if 0
int removeElement(vector<int>& nums, int val) {
    int i = 0, j = nums.size()-1;
    while(i <= j){
        while(nums[i] != val && i <= j)
            i++;
        while(nums[j] == val && i <= j)
            j--;
        if(i < j)
            swap(nums[i], nums[j]);
    }
    nums.resize(i);
    return i;
}
#endif
int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for(int j = 0; j < nums.size(); j++)
        if(nums[j] != val){
            nums[i] = nums[j];
            i++;
        }
    nums.resize(i);
    return i;
}
int main() {
    vector<int> p;
    p.push_back(1);
    p.push_back(1);
    cout << removeElement(p, 1);
    for(auto v:p)
        cout << v;
}