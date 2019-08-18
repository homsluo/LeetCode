//
// Created by homsl on 2019/8/9.
//
vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    if(!nums.size())
        return res;
    int k = nums.size()/3, cand1 = NULL, cand2 = NULL, count1 = 0, count2 = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == cand1)
            count1++;
        else if(nums[i] == cand2)
            count2++;
        else if(count1 == 0){
            count1++;
            cand1 = nums[i];
        }
        else if(count2 == 0){
            count2 ++;
            cand2 = nums[i];
        }
        else{
            count1--;
            count2--;
        }
    }
    count1 = 0, count2 = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == cand1)
            count1++;
        else if(nums[i] == cand2)
            count2++;
    }
    if(count1 > k)
        res.push_back(cand1);
    if(count2 > k)
        res.push_back(cand2);
    return res;
}

vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    if(!nums.size())
        return res;
    sort(nums.begin(), nums.end());
    int k = nums.size()/3, count = 1, i = 0;
    while((i+k) < nums.size()){
        if(nums[i] == nums[i+k]){
            res.push_back(nums[i]);
            i += k;
            while((i+1) < nums.size() && nums[i] == nums[i+1])
                i++;
            i++;
        }
        else{
            while((i+1) < nums.size() && nums[i] == nums[i+1])
                i++;
            i++;
        }
    }
    return res;
}

vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    if(!nums.size())
        return res;
    sort(nums.begin(), nums.end());
    int k = nums.size()/3, count = 1, i = 1;
    for(; i < nums.size(); i++){
        if(nums[i] == nums[i-1])
            count++;
        else{
            if(count > k)
                res.push_back(nums[i-1]);
            count = 1;
        }
    }
    if(count > k)
        res.push_back(nums[i-1]);
    return res;
}
