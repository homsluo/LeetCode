//
// Created by homsl on 2019/6/19.
//
vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int,int> nums;
    int complement = 0;
    vector<int> ans;
    for(int i = 0; i < numbers.size(); i++){
        complement = target - numbers[i];

        if(nums.find(complement) != nums.end()){
            ans.push_back(nums[complement]);
            ans.push_back(i+1);
        }
        nums[numbers[i]] = i+1;
    }
    return ans;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size()-1;
    vector<int> ans;
    while(i < j){
        if(numbers[i] + numbers[j] == target){
            ans.push_back(i+1);
            ans.push_back(j+1);
            break;
        }
        else if(numbers[i] + numbers[j] < target)
            i++;
        else
            j--;
    }
    return ans;
}
