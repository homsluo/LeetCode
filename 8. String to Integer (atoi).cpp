//
// Created by homsl on 2019/10/6.
//
int myAtoi(string str) {            // Brute Force
    if(str.size() < 1)
        return 0;
    int n = str.size();
    int i = 0;
    while(i < n && str[i] == ' ')     // skip ' '
        i++;
    if(i >= n)      // if all ' '
        return 0;
    int np = 0;     // 0 pos; 1 neg.
    if(str[i] == '+' || str[i] == '-')
        np = str[i++] == '-'? 1 : 0;      // mark sign and skip the sign
    else if(str[i] < 48 || str[i] > 57)     // if start with no number
        return 0;

    while(i < n && str[i] == '0')     // skip 0s
        i++;

    if(i >= n || (str[i] < 48 || str[i] > 57))      // if no number > 0 or start with no number
        return 0;

    int start = i;
    while(i < n){
        if(str[i] < 48 || str[i] > 57)      // stop number count
            break;
        i++;
    }
    if(i - start > 10 || (i-start == 10 && str[start] > '2') )
        return np == 1 ? INT_MIN : INT_MAX;
    i--;

    double res = 0;
    for(int j = i; j >= start; j--){
        res += (str[j]-48) * pow(10, i-j);
    }

    res = np == 1?(-res):res;
    if(res > INT_MAX)
        return INT_MAX;
    else if(res < INT_MIN)
        return INT_MIN;
    return res;
}

//----------------------------------------------------------------------------------------------
int myAtoi(string str) {
    if(str.size() < 1)
        return 0;
    int n = str.size(), np = 1;
    long long int res = 0;
    for(int i = 0; i < n;){
        i = str.find_first_not_of(' ');
        if(i == str.npos)
            return 0;
        if(str[i] == '-' || str[i] == '+')
            np = str[i++] == '-'? -1: 1;
        while(str[i] >= '0' && str[i] <= '9'){
            res = res*10 + (str[i++]-'0');
            if(res*np >= INT_MAX) return INT_MAX;
            if(res*np <= INT_MIN) return INT_MIN;
        }
        return res*np;
    }
    return 0;
}