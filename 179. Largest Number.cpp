//
// Created by homsl on 2020/4/25.
//
string largestNumber(vector<int>& nums) {
    if(nums.size() < 1)
        return "";
    if(nums.size() < 2)
        return to_string(nums[0]);
    sort(nums.begin(), nums.end(), compare);
    string ans;
    for(int num:nums){
        ans += to_string(num);
    }
    int idx = 0;
    while(idx < ans.size() && ans[idx] == '0')
        idx++;
    if(idx == ans.size())
        return "0";
    return ans.substr(idx);
}

static bool compare(int x, int y){
    string a = to_string(x);
    string b = to_string(y);
    return (a+b > b+a)?1:0;
}
