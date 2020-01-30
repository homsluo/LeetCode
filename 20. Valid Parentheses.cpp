//
// Created by homsl on 2019/11/26.
//
bool isValid(string s) {
    vector<char> stack;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            stack.push_back(')');
        else if(s[i] == '[')
            stack.push_back(']');
        else if(s[i] == '{')
            stack.push_back('}');
        else{
            if(stack.empty() || stack.back() != s[i])
                return false;
            stack.pop_back();
        }
    }
    return stack.empty();
}
