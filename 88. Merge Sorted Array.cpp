//
// Created by homsl on 2019/6/18.
//
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i = m-1, j = n-1, r = m+n-1;
    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j])
            nums1[r--] = nums1[i--];
        else
            nums1[r--] = nums2[j--];
    }
    while(j >= 0)
        nums1[r--] = nums2[j--];
}