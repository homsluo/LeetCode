#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
    if (!target) {
        res.push_back(combination);
        return;
    }
    for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
        combination.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], res, combination, i);
        combination.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > res;
    vector<int> combination;
    sort(candidates.begin(), candidates.end());
    combinationSum(candidates, target, res, combination, 0);
    return res;
}


int main(){
    vector<int> test = {2,3,6,7};
    vector<vector<int>> ans = combinationSum(test,7);
    for(vector<int> v:ans){
        for(int m:v){
            cout << m << ' ';
        }
        cout << endl;
    }
}