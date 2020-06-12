//
// Created by homsl on 2020/4/4.
//
int evalRPN(vector<string>& tokens) {
    if(tokens.empty())
        return 0;
    stack<int> stk;
    int num;
    for(int i = 0; i < tokens.size(); i++){
        if(isdigit(tokens[i][0]) || isdigit(tokens[i][1])){
            num = stoi(tokens[i]);
            stk.push(num);
        }
        else{
            int op2 = stk.top();
            stk.pop();
            int op1 = stk.top();
            stk.pop();
            if(tokens[i][0] == '+')
                num = op1+op2;
            if(tokens[i][0] == '-')
                num = op1-op2;
            if(tokens[i][0] == '*')
                num = op1*op2;
            if(tokens[i][0] == '/')
                num = op1/op2;
            stk.push(num);
        }
    }
    return stk.top();
}
