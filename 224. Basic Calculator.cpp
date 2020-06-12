//
// Created by homsl on 2020/5/25.
//
int calculate(string s){
    if(s.empty())
        return 0;
    // Use 2 Stack, 1 for operand, 1 for operator
    stack<int> number;
    stack<pair<int, int>> op;   // pair<operator, parenthesis level>, 1:+, 0:-
    int idx = 0;
    int res = 0;
    int level = 0;
    for(; idx < s.size(); idx++){
        if(s[idx] == ' ')
            continue;
        else if(isdigit(s[idx]))
            number.push(readnumber(s, idx));
        else if(s[idx] == '(')
            level++;
        else if(s[idx] == ')')
            level--;
        else{
            int temp = s[idx]=='+'?1:0;
            while(!op.empty() && level <= op.top().second){
                int num1 = number.top();
                number.pop();
                int num2 = number.top();
                number.pop();
                if(op.top().first)
                    res = num1+num2;
                else
                    res = num2-num1;
                op.pop();
                number.push(res);
            }
            op.push({temp, level});
        }
    }
    while(!op.empty()){
        int num1 = number.top();
        number.pop();
        int num2 = number.top();
        number.pop();
        if(op.top().first)
            res = num1+num2;
        else
            res = num2-num1;
        op.pop();
        number.push(res);
    }
    return number.top();
}

int readnumber(string& s, int& idx){
    int ans = 0;
    while(isdigit(s[idx])){
        ans = ans*10+(s[idx]-'0');
        idx++;
    }
    idx--;
    return ans;
}
