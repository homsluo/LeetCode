//
// Created by homsl on 2020/1/10.
//
string countAndSay(int n) {
    if(n <= 0)
        return "";
    string str = "1";
    for(int i = 1; i < n; i++){
        int count = 0;
        char prev = '.';
        string res;
        for(int j = 0; j < str.size(); j++){
            if(str[j] == prev || prev == '.')
                count++;
            else{
                res += char('0'+count);
                res += prev;
                count = 1;
            }
            prev = str[j];
        }
        res += char('0'+count);
        res += prev;
        str = res;
    }
    return str;
}
