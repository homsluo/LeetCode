//
// Created by homsl on 2019/8/9.
//

int maxProduct(vector<int>& nums) {
    if(!nums.size())
        return 0;
    int max_prod = -9999;

    for(int j = 0; j < 2; j++){
        int prod = 1, prod_all = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                prod = 1;
                prod_all = 1;
                max_prod = max(0, max_prod);
            }
            else if(nums[i] < 0){
                prod = 1;
                prod_all *= nums[i];
                max_prod = max(max_prod, prod_all);
            }
            else{
                prod *= nums[i];
                prod_all *= nums[i];
                max_prod = max(max_prod, max(prod, prod_all));
            }
        }
        reverse(nums.begin(), nums.end());
    }
    return max_prod;
}