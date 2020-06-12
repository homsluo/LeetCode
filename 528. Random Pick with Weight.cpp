//
// Created by homsl on 2020/6/5.
//
Solution(vector<int>& w) {
// Construct accumulate array
accu = vector<int>(w.size(), w[0]);
for(int i = 1; i < w.size(); i++)
accu[i] = w[i]+accu[i-1];
}

int pickIndex() {
    int rnum = rand()%accu.back();
    int left = 0;
    int right = accu.size()-1;
    while(left < right){
        int mid = (left+right)/2;
        if(accu[mid] > rnum)
            right = mid;
        else
            left = mid+1;
    }
    return right;
}
