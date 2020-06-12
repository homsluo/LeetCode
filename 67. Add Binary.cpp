//
// Created by homsl on 2020/1/30.
//
string addBinary(string a, string b) {
    if(a.empty()||b.empty())
        return a.empty() ? b : a;
    string res;
    int i = a.size()-1;
    int j = b.size()-1;
    int carry = 0;
    while(i >= 0 || j >= 0 || carry > 0){
        int sum = carry;
        if(i >= 0){
            sum += a[i--]-'0';
        }
        if(j >= 0){
            sum += b[j--]-'0';
        }
        res += char(sum%2+'0');
        carry = sum/2;
    }
    reverse(res.begin(), res.end());
    return res;
}
