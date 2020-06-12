//
// Created by homsl on 2020/5/20.
//
int findKthLargest(vector<int>& nums, int k) {
    map<int,int> sort;
    for(int num:nums){
        sort[num]++;
    }
    auto it = sort.end();
    int ans;
    while(k > 0){
        k -= it->second;
        ans = it->first;
        it--;
    }
    return ans;
}

// Priority Queue
int findKthLargest(vector<int>& nums, int k) {
    // use priority queue
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int num:nums){
        pq.push(num);
        if(pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

// Quick Sort
int findKthLargest(vector<int>& nums, int k) {
    // Quick sort and branch deduct
//    randomize(nums);
    int left = 0;
    int right = nums.size()-1;
    while(left <= right){
        int pivot = partition(nums, left, right);
        if(pivot == nums.size()-k)
            return nums[pivot];
        else if(pivot < nums.size()-k)
            left = pivot+1;
        else
            right = pivot-1;
    }
    return 0;
}

//void randomize(vector<int>& nums){
//    srand(time(NULL));
//    for(int i = nums.size()-1; i > 0; i--){
//        int r = rand()%i;
//        swap(nums[i], nums[r]);
//    }
//}

int partition(vector<int>& nums, int left, int right){
    int slow = left-1;
    int fast = left;
    for(; fast < right; fast++){
        if(nums[fast] < nums[right])
            swap(nums[++slow], nums[fast]);
    }
    swap(nums[++slow], nums[fast]);
    return slow;
}
