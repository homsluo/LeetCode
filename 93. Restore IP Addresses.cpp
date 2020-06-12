//
// Created by homsl on 2020/2/13.
//
vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if(s.empty())
        return res;
    string cur;
    helper(res, s, cur, 0);
    return res;
}

void helper(vector<string>& res, string s, string cur, int field){
    if(field == 4 && s.empty())
        res.push_back(cur.substr(1));
    else if(field == 4 || s.empty() || (s.size() > (4-field)*3))
        return;
    else{
        helper(res, s.substr(1), cur + '.'+s.substr(0,1), field+1);
        if(s[0] != '0' && s.size() > 1){
            helper(res, s.substr(2), cur + '.'+s.substr(0,2), field+1);
            if(s.size() > 2 && s.substr(0,3) <= "255"){
                helper(res, s.substr(3), cur + '.' + s.substr(0,3), field+1);
            }
        }
    }
}
