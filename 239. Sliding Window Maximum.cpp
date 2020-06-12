//
// Created by homsl on 2020/5/31.
//

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //  Keep max number at begin, every time add new number from back and pop those number less and before the new number
    vector<int> ans;
    deque<int> sw;
    for(int i = 0; i < k && i < nums.size(); i++){
        while(!sw.empty() && nums[i] > nums[sw.back()])
            sw.pop_back();
        sw.push_back(i);
    }
    ans.push_back(nums[sw.front()]);
    for(int i = k; i < nums.size(); i++){
        if(i-sw.front() == k)
            sw.pop_front();
        while(!sw.empty() && nums[i] > nums[sw.back()])
            sw.pop_back();
        sw.push_back(i);
        ans.push_back(nums[sw.front()]);
    }
    return ans;
}