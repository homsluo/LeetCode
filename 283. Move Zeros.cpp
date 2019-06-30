//
// Created by homsl on 2019/6/22.
//
void movezero(vector<int> nums){
    int index = 0;
    bool ex = false;
    for(int i = 0; i < nums.size(); i++){
        if(!nums[i] && !ex){   //  this is the first zero
            index = i;
            ex = !ex;
        }
        else if(nums[i] && ex){
            swap(nums[i], nums[index]);
            index++;        // this is first zero
        }
    }
}
