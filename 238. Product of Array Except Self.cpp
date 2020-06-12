vector<int> productExceptSelf(vector<int>& nums) {
    int prod = 1, count = 0, pos = 0;
    vector<int> res(nums.size(), 0);

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            if(!count++)
                pos = i;
            else
                return res;
            continue;
        }
        prod *= nums[i];
    }

    if(count)
        res[pos] = prod;
    else
        for(int i = 0; i < nums.size(); i++)
            res[i] = prod/nums[i];
    return res;
}

// --------------------------------------------------------------------------------
// Time:O(n), constant space, without division
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    int prod = 1;
    for(int i = 1; i < nums.size(); i++){
        prod *= nums[i-1];
        res[i] = prod;
    }
    prod = 1;
    for(int j = nums.size()-2; j >= 0; j--){
        prod *= nums[j+1];
        res[j] *= prod;
    }
    return res;
}
