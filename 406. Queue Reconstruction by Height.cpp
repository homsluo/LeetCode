//
// Created by homsl on 2020/6/6.
//
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if(people.empty())
            return people;
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> li;
        for(int i = 0; i < people.size(); i++){
            auto it = li.begin();
            advance(it, people[i][1]);
            li.insert(it, people[i]);
        }
        vector<vector<int>> ans(li.begin(), li.end());
        return ans;
    }

    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
};
