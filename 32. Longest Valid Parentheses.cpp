//
// Created by homsl on 2020/1/8.
//

int longestValidParentheses(string s) {
    vector<int> stack;
    int lm = -1, len = s.size(), res = 0;

    for(int i = 0; i < len; i++){
        if(s[i] == '(')
            stack.push_back(i);
        if(s[i] == ')'){
            if(stack.empty())
                lm = i;
            else{
                stack.pop_back();
                if(stack.empty())
                    res = max(res, i-lm);
                else
                    res = max(res, i-stack.back());
            }
        }
    }
    return res;
}