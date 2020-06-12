//
// Created by homsl on 2020/4/11.
//
string fractionToDecimal(int numerator, int denominator) {
    if(numerator == 0)
        return "0";
    string res;
    if((numerator < 0 && denominator > 0) ||
       (numerator > 0 && denominator < 0))
        res += '-';

    long long num = numerator == INT32_MIN ? -(long long)numerator : abs(numerator);
    long long den = denominator == INT32_MIN ? -(long long)denominator : abs(denominator);

    res += to_string(num/den);
    long long rem = num % den;
    if(rem == 0)
        return res;

    res += '.';
    unordered_map<long long, int> map;
    while(rem != 0){
        if(map.count(rem)){
            res.insert(map[rem], "(");
            res += ')';
            return res;
        }
        else{
            map[rem] = res.size();
            res += to_string(rem*10/den);
            rem = rem*10%den;
        }
    }
    return res;
}
