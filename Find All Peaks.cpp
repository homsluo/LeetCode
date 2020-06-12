//
// Created by homsl on 2020/4/21.
//
/*Question:
Given an array of integers, representing points in a graph, find all points which are the 'peak' points in a graph.

Arr: [ 1, 4, 3, -1, 5, 5, 7, 4, 8 ]

Peaks: [4, 7, 8]

If you plot the numbers in the array as a graph, you'll see it rising and falling based on the value. For a point to qualify as a 'peak', the graph should rise to the 'peak' and then fall, exceptions being the first and last elements. For the first element to be a peak, the graph should fall after it. For the last element to be a peak, the graph should rise before it.

Try to solve in O(n) time.
 */

vector<int> func(vector<int> arr){
    int n = arr.size();
    vector<int> peak;
    if(n <= 1)
        return peak;
    if(arr[0] > arr[1])
        peak.push_back(arr[0]);
    for(int i = 1; i < n-1; i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
            peak.push_back(arr[i]);
    }
    if(arr[n-1] > arr[n-2])
        peak.push_back(arr[n-1]);
    return peak;
}
