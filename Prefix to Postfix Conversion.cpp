//
// Created by homsl on 2020/4/21.
//
/*Prefix : An expression is called the prefix expression if the operator appears in the expression before the operands. Simply of the form (operator operand1 operand2).
Example : *+AB-CD (Infix : (A+B) * (C-D) )

Postfix: An expression is called the postfix expression if the operator appears in the expression after the operands. Simply of the form (operand1 operand2 operator).
Example : AB+CD-* (Infix : (A+B * (C-D) )

Given a Prefix expression, convert it into a Postfix expression.
Conversion of Prefix expression directly to Postfix without going through the process of converting them first to Infix and then to Postfix is much better in terms of
computation and better understanding the expression (Computers evaluate using Postfix expression).

Examples:
Input :  Prefix :  *+AB-CD
Output : Postfix : AB+CD-*
Explanation : Prefix to Infix :  (A+B) * (C-D)
              Infix to Postfix :  AB+CD-*

Input :  Prefix :  *-A/BC-/AKL
Output : Postfix : ABC/-AK/L-*
Explanation : Prefix to Infix :  A-(B/C)*(A/K)-L
              Infix to Postfix : ABC/-AK/L-*
 */

string preToPost(string s){
    if(s.empty())
        return s;
    int n = s.size();
    stack<string> stk;
    for(int i = n-1; i >= 0; i--){
        char cur = s[i];
        if(!isalpha(cur)){
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            op1 += op2 + cur;
            stk.push(op1);
        }
        else
            stk.push(string(1,cur));
    }
    return stk.top();
}