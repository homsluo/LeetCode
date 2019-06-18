//
// Created by homsl on 2019/6/18.
//
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> last(3,1);
    vector<int> cur(4,1);
    for(auto v: last)
        cout << v <<' ';
    cout << endl;
    last = cur;
    for(auto c:last)
        cout << c << ' ';
}

