//
// Created by homsl on 2019/6/18.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ctime>
using namespace std;

int main(){
    vector<int> nums = {0,1,2,4,5};
    string s = to_string(nums[0])+"->"+to_string(nums[3]);
    cout << s;
}

