//
// Created by homsl on 2020/5/26.
//
int calculate(string s) {
    if(s.empty())
        return 0;
    deque<int> operands;
    deque<char> ops;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ')
            continue;
        if(isdigit(s[i]))
            operands.push_back(readNumber(s, i));
        else if(ops.empty() || (ops.back() != '*' && ops.back() != '/'))
            ops.push_back(s[i]);
        else{
            int op1 = operands.back();
            operands.pop_back();
            int op2 = operands.back();
            operands.pop_back();
            if(ops.back() == '*')
                operands.push_back(op1*op2);
            else
                operands.push_back(op2/op1);
            ops.pop_back();
            ops.push_back(s[i]);
        }
    }
    if(ops.empty())
        return operands.front();
    else if(ops.back() == '*'|| ops.back() == '/'){
        int op1 = operands.back();
        operands.pop_back();
        int op2 = operands.back();
        operands.pop_back();
        if(ops.back() == '*')
            operands.push_back(op1*op2);
        else
            operands.push_back(op2/op1);
        ops.pop_back();
    }
    while(!ops.empty()){
        int op1 = operands.front();
        operands.pop_front();
        int op2 = operands.front();
        operands.pop_front();
        if(ops.front() == '+')
            operands.push_front(op1+op2);
        else
            operands.push_front(op1-op2);
        ops.pop_front();
    }
    return operands.front();
}

int readNumber(string& s, int& i){
    int ans = 0;
    while(isdigit(s[i])){
        ans = ans*10+(s[i]-'0');
        i++;
    }
    i--;
    return ans;
}