//
// Created by homsl on 2019/8/9.
//
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if(!nums.size())
        return res;
    if(nums.size() == 1){
        res.push_back(to_string(nums[0]));
        return res;
    }
    int i = 0, j = 1;
    for(; j < nums.size(); j++){
        if((long int)nums[j]-(long int)nums[j-1] == 1)
            continue;
        if(i == j-1)
            res.push_back(to_string(nums[i]));
        else
            res.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
        i = j;
    }
    if(i == j-1)
        res.push_back(to_string(nums[i]));
    else
        res.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
    return res;
}
