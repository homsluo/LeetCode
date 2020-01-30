//
// Created by homsl on 2020/1/15.
//

string multiply(string num1, string num2) {
    if(num1.empty() || num2.empty())
        return "0";
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> res(len1+len2, 0);
    for(int i = len1-1; i >= 0; i--){
        for(int j = len2-1; j >= 0; j--){
            int mul = (num1[i]-'0') * (num2[j]-'0');
            int poslow = i+j+1;
            int poshigh = i+j;
            mul += res[poslow];
            res[poslow] = mul%10;
            res[poshigh] += mul/10;
        }
    }
    string ans;
    for(int i = 0; i < len1+len2; i++){
        if(!(ans.size() == 0 && res[i] == 0))
            ans += char(res[i]+'0');
    }
    return (ans.size() == 0)? "0" : ans;
}