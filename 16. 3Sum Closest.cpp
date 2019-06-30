//
// Created by homsl on 2019/6/26.
//
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() <= 3){
        int sum = 0;
        for(int v:nums)
            sum += v;
        return sum;
    }
    int ans = nums[0]+nums[1]+nums[2];
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-2; i++){
        int j = i+1;
        int k = nums.size()-1;
        while(j < k){
            if(abs(nums[i]+nums[j]+nums[k]-target) <= abs(ans-target)){
                ans = nums[i]+nums[j]+nums[k];
                if(target < ans)
                    k--;
                else if(target > ans)
                    j++;
                else
                    return ans;
            }
            else{
                if(target < nums[i]+nums[j]+nums[k])
                    k--;
                else
                    j++;
            }
        }
    }
    return ans;
}

int threeSumClosest(vector<int>& nums, int target) { // improved
    if(nums.size() <= 3){
        int sum = 0;
        for(int v:nums)
            sum += v;
        return sum;
    }
    int ans = nums[0]+nums[1]+nums[2];
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-2; i++){
        int j = i+1;
        int k = nums.size()-1;
        while(j < k){
            int temp_sum = nums[i]+nums[j]+nums[k];
            if(abs(target-temp_sum) < abs(target-ans))
                ans = temp_sum;

            if(target > temp_sum)
                j++;
            else if(target < temp_sum)
                k--;
            else
                return temp_sum;
        }
    }
    return ans;
}
