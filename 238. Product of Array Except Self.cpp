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

