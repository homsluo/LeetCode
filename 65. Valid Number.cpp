//
// Created by homsl on 2020/1/30.
//
bool isNumber(string s) {
    if(s.empty())
        return false;
    int i = 0;
    int n = s.size();
    while(i < n && s[i] == ' ')
        i++;
    if(i < n && (s[i] == '+' || s[i] == '-'))
        i++;
    bool isDigit = false;
    // 042 is valid
    while(i < n && (s[i] >= '0' && s[i] <= '9')){
        i++;
        isDigit = true;
    }
    // 3. and .42 are valid
    if(s[i] == '.'){
        i++;
        while(i < n && (s[i] >= '0' && s[i] <= '9')){
            i++;
            isDigit = true;
        }
    }
    //3.e2 and .43e2 are valid
    if(i < n && s[i] == 'e' && isDigit){
        i++;
        isDigit = false;
        if(i < n && (s[i] == '+' || s[i] == '-'))
            i++;
        while(i < n && (s[i] >= '0' && s[i] <= '9')){
            i++;
            isDigit = true;
        }
    }
    while(i < n && s[i] == ' ')
        i++;
    return (isDigit && i == n);
}
