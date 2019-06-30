#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int thirdMax(vector<int>& nums) {
    int first, second, third;
    bool fe, se, te;
    fe = se = te = false;
    for(int i = 0; i < nums.size(); i++){
        if(!fe) {
            first = nums[i];
            fe = true;
        }
        else if(fe && !se){
            if(nums[i] > first){
                second = first;
                se = true;
                first = nums[i];
            }
            else if(nums[i] < first){
                second = nums[i];
                se = true;
            }
        }
        else if(fe && se && !te){
            if(nums[i] > first){
                third = second;
                te = true;
                second = first;
                first = nums[i];
            }
            else if(nums[i] > second && nums[i] < first){
                third = second;
                te = true;
                second = nums[i];
            }
            else if(nums[i] < second){
                third = nums[i];
                te = true;
            }
        }
        else if(fe && se && te){
            if(nums[i] > first){
                third = second;
                second = first;
                first = nums[i];
            }
            else if(nums[i] > second && nums[i] < first){
                third = second;
                second = nums[i];
            }
            else if(nums[i] > third && nums[i] < second){
                third = nums[i];
            }
        }
    }
    if(te)
        return third;
    return first;
}

int main(){
    vector<int> test;
    test.push_back(5);
    test.push_back(2);
    test.push_back(4);
    test.push_back(1);
    test.push_back(3);
    test.push_back(6);
    test.push_back(0);
    cout << thirdMax(test);
}