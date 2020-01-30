//
// Created by homsl on 2019/6/18.
//
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;
void dfs(string& res, string& path, int k, int& n, int& count, vector<int>& used){
    if(path.size() == n)
        count++;
    if(count == k){
        res = path;
        n = 0;
    }

    for(int i = 1; i <= n; i++){
        if(!used[i-1]){
            path += char(i) + '0';
            used[i-1] = 1;
            dfs(res, path, k, n, count, used);
            used[i-1] = 0;
            path.pop_back();
        }
    }
    return;
}
string getPermutation(int n, int k) {
    string path;
    string res;
    vector<int> used(n, 0);
    int count = 0;
    dfs(res, path, k, n, count, used);
    return res;
}

int main(){
    vector<int> a = {1,2,3,4};
    a.erase(a.begin()+1);
    for(auto i:a)
        cout << i << ' ';
}