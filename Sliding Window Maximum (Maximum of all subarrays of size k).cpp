//
// Created by homsl on 2020/4/22.
//
/* Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
 * Examples :
 * Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3
 * Output: 3 3 4 5 5 5 6
 * Input: arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, K = 4
 * Output: 10 10 10 15 15 90 90
*/

vector<int> printKMax(vector<int> arr, int k){
    int n = arr.size();
    vector<int> max;
    deque<int> sw(k);

    int idx = 0;
    for(; idx < k; idx++){
        while(!sw.empty() && arr[idx] >= arr[sw.back()]){
            sw.pop_back();
        }
        sw.push_back(idx);
    }

    for(; idx < n; idx++){
        max.push_back(arr[sw.front()]);
        while(!sw.empty() && sw.front() <= idx-k)
            sw.pop_front();

        while(!sw.empty() && arr[idx] >= arr[sw.back()])
            sw.pop_back();
        sw.push_back(idx);
    }
    max.push_back(arr[sw.front()]);
    return max;
}