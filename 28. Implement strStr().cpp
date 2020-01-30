//
// Created by homsl on 2020/1/6.
//
int strStr(string haystack, string needle) {
    if(needle.empty())
        return 0;
    int res = -1;
    for(int i = 0; i < haystack.size(); i++){
        if(haystack[i] == needle[0]){
            for(int j = 0; j < needle.size(); j++){
                if(haystack[i+j] != needle[j])
                    break;
                if(j == needle.size()-1)
                    return i;
            }
        }
    }
    return res;
}
//-------------------------
int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    for (int i = 0; i <= m - n; i++) {
        int j = 0;
        for (; j < n; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return -1;
}
// KMP

int strStr(string haystack, string needle) {
    if(needle.empty())
        return 0;
    int m = haystack.size(), n = needle.size();
    vector<int> pre = KMP(needle);
    int j = 0, res = -1;
    for(int i = 0; i < m;){
        if(haystack[i] == needle[j]){
            i++,j++;
        }
        else{
            j ? j = pre[j-1] : i++;
        }
        if(j == n)
            return i-j;
    }
    return res;
}

vector<int> KMP(string& needle){
    vector<int> pre(needle.size(), 0);
    for(int i = 0, j = 1; j < needle.size();){
        if(needle[i] == needle[j]){
            pre[j] = i+1;
            i++;
            j++;
        }
        else{
            if(i == 0)
                j++;
            else
                i = pre[i-1];
        }
    }
    return pre;
}