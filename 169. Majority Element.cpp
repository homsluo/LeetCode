//
// Created by homsl on 2019/6/20.
//
int majorityElement(vector<int>& nums) {
    int ans = nums[0], q = nums.size()/2;
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++){
        if(map.find(nums[i]) == map.end()){
            map[nums[i]] = i;
            int count = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] == nums[i])
                    count++;
                if(count > q)
                    return nums[i];
            }
        }
    }
    return ans;
}

int majorityElement(vector<int>& nums) {
    map<int, int> counts;
    for(int i = 0; i < nums.size(); i++){
        if(counts.find(nums[i]) != counts.end())
            counts[nums[i]] += 1;
        else
            counts[nums[i]] = 1;
    }

    int ans = 0, numbers = 0;
    for(auto v:counts){
        if(v.second > numbers){
            ans = v.first;
            numbers = v.second;
        }
    }
    return ans;
}

int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}
