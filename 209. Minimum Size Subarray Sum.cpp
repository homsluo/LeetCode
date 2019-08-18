//
// Created by homsl on 2019/8/9.
//
int minSubArrayLen(int s, vector<int>& nums) {
    if(!nums.size())
        return 0;
    int res = nums.size()+1;
    for(int i = 0; i < nums.size(); i++){
        int sum = nums[i];
        int count = 1;
        int j = i+1;
        while(j < nums.size() && sum < s){
            sum += nums[j++];
            count++;
        }
        if(sum >= s)
            res = min(count,res);
    }
    if(res == nums.size()+1)
        return 0;
    return res;
}

int minSubArrayLen(int s, vector<int>& nums) {
    if(!nums.size())
        return 0;
    int i = 0, j = 1, sum = nums[0], count = 1;
    while(j < nums.size() && sum < s){
        sum += nums[j++];
        count++;
    }
    int res = count;
    if(sum < s)
        return 0;
    else{
        while(j < nums.size()){
            if((sum-s) < nums[i]){
                sum += nums[j++];
                count++;
            }
            else{
                sum -= nums[i++];
                count--;
                res = min(res, count);
            }
        }
        while((sum-s) >= nums[i]){
            sum -= nums[i++];
            count--;
            res = min(res, count);
        }
    }
    return res;
}
