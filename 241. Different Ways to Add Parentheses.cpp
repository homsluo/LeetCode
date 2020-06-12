//
// Created by homsl on 2020/6/2.
//
namespace homs{
    int add(int a, int b){return a+b;};
    int minus(int a, int b){return a-b;};
    int multiply(int a, int b){return a*b;};
}

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> res;
        return ways(input, res);
    }

    const vector<int>& ways(const string& input, unordered_map<string, vector<int>>& res){
        if(res.count(input))
            return res[input];

        vector<int> ans;
        for(int i = 0; i < input.size(); i++){
            char op = input[i];
            if(op == '+' || op == '-' || op == '*'){
                const string& left = input.substr(0, i);
                const string& right = input.substr(i+1);
                const vector<int>& leftres = ways(left, res);
                const vector<int>& rightres = ways(right, res);

                function<int(int, int)> f;      // function pointer

                switch(op){
                    case '+': f = homs::add; break;
                    case '-': f = homs::minus; break;
                    case '*': f = homs::multiply; break;
                }

                for(auto l:leftres)
                    for(auto r:rightres)
                        ans.push_back(f(l,r));
            }
        }

        if(ans.empty())
            ans.push_back(stoi(input));
        res[input] = ans;
        return res[input];
    }
};
