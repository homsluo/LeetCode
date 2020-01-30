//
// Created by homsl on 2019/10/1.
//
int lengthOfLIS(vector<int>& nums) {        //dp
    int n = nums.size();
    if(n < 2)
        return n == 1 ? 1 : 0;
    vector<int> dp(n, 1);
    int res = 1;
    for(int i = 1; i < n; i++)
    {
        dp[i] = 1+findMax(i, dp, nums);
        res = max(res, dp[i]);
    }
    return res;
}

int findMax(int j, vector<int>& dp, vector<int>& nums)
{
    int res = 0;
    for(int i = 0; i < j; i++)
    {
        if(nums[i] < nums[j])
            res = max(dp[i], res);
    }
    return res;
}

//------------------------------------------------------------------------//
int lengthOfLIS(vector<int>& nums) {            //greedy
    int n = nums.size();
    if(n < 2)
        return n == 1 ? 1 : 0;
    vector<int> grd;
    grd.push_back(nums[0]);
    for(int i = 1; i < n; i++)
    {
        if(nums[i] > grd.back())
            grd.push_back(nums[i]);
        else if(nums[i] < grd.back())
        {
            int l = 0, r = grd.size()-1;
            while(l < r)
            {
                int mid = (l+r)/2;
                if(grd[mid] < nums[i])
                    l = mid + 1;
                else if(grd[mid] == nums[i]){
                    l = mid;
                    break;
                }
                else
                    r = mid;
            }
            grd[l] = nums[i];
        }
    }
    return grd.size();
}

