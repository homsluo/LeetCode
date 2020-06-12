//
// Created by homsl on 2020/2/12.
//
vector<int> grayCode(int n) {
    vector<int> res;
    for(int i = 0; i < (1 << n); i++){
        res.push_back((i^(i>>1)));
    }
    return res;
}
