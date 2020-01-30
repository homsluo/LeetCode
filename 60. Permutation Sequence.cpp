//
// Created by homsl on 2020/1/29.
//
string getPermutation(int n, int k) {
    string path;
    string res;
    vector<int> used(n, 0);
    int count = 0;
    dfs(res, path, k, n, count, used);
    return res;
}

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

// Advanced

string getPermutation(int n, int k) {
    string res;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        nums.push_back(i+1);
    }
    int f[n];
    f[0] = 1;
    for(int i = 1; i < n; i++)
        f[i] = i*f[i-1];
    k--;
    for(int i = 0; i < n; i++){
        int g = k/f[n-i-1];
        res += char(nums[g])+'0';
        nums.erase(nums.begin()+g);
        k = k % f[n-i-1];
    }
    return res;
}
