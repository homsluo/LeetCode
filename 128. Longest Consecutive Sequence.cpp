//
// Created by homsl on 2020/3/16.
//
int longestConsecutive(vector<int>& nums) {
    int size = nums.size();
    if(size == 0 || size == 1)
        return size;

    unordered_map<int, int> map;
    int res = 1;

    for(int i = 0; i < size; i++){
        int curr = nums[i];
        int len = 1;
        if(!map.count(curr))
            map[curr] = 1;
        else
            continue;

        if(map.count(curr+1) && map.count(curr-1)){
            len = map[curr-1]+map[curr+1]+1;
            map[curr-map[curr-1]] = len;
            map[curr+map[curr+1]] = len;
        }
        else if(map.count(curr+1)){
            len = map[curr+1]+1;
            map[curr] = len;
            map[curr+map[curr+1]] = len;
        }
        else if(map.count(curr-1)){
            len = map[curr-1]+1;
            map[curr] = len;
            map[curr-map[curr-1]] = len;
        }
        res = max(res, len);
    }

    return res;
}

//----------------------------------------------------------------------------------------------------------------

int longestConsecutive(vector<int>& nums) {
    int size = nums.size();
    if(size == 0 || size == 1)
        return size;

    unordered_map<int, int> map;
    int res = 1;

    for(int i:nums){
        if(map.count(i))
            continue;

        auto it_l = map.find(i-1);
        auto it_r = map.find(i+1);

        int l = it_l != map.end()?it_l->second:0;
        int r = it_r != map.end()?it_r->second:0;
        int len = l+r+1;

        map[i] = map[i-l] = map[i+r] = len;
        res = max(res, len);
    }

    return res;
}
