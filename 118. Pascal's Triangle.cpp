//
// Created by homsl on 2019/6/18.
//
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows){
    vector<vector<int>> ans;
    int i = 1;
    while(i <= numRows){
        vector<int> temp(i, 1);
        if(i > 2){
            for(int j = 1; j < i-1; j++){
                temp[j] = ans[i-2][j-1] + ans[i-2][j];
            }
        }
        ans.push_back(temp);
        i++;
    }
    return ans;
}

int main(){
    vector<vector<int>> PT = generate(5);
    for(int i = 0; i < 5; i++){
        for(auto v:PT[i])
            cout << v << ' ';
        cout << endl;
    }
}
