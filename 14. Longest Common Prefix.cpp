//
// Created by homsl on 2019/11/15.
//
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())
        return "";
    string res = strs[0];
    for(int i = 1; i < strs.size(); i++){
        int j = 0;
        while(j < res.size() && j < strs[i].size()){
            if(res[j] != strs[i][j])
                break;
            j++;
        }
        res = res.substr(0,j);
    }
    return res;
}

//-------------------------------------------------------------
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())
        return "";
    string res = "";
    for(int i = 0; i < strs[0].size(); i++){
        int j = 1;
        char temp = strs[0][i];
        while(j < strs.size()){
            if(strs[j][i] != temp)
                return res;
            j++;
        }
        res += temp;
    }
    return res;
}
