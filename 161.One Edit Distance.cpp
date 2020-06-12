//
// Created by homsl on 2020/4/10.
//
/* Given two strings S and T, determine if they are both one edit distance apart.
 *
 * Example:
 * S = "abc"
 * T = "ab"
 *  return True
 * --------------------------------
 * S = "abcd"
 * T = "abef"
 *  return False
*/


/* 3 Cases: Delete, Replace, Insert
 * if s.size()-t.size() > 1 return false
 * if s.size()-t.size() = 1 delete/insert
 * if s.size()-t.size() = 0 replace
 */

bool isOneEditDistance(string s, string t){
    int slen = s.size();
    int tlen = t.size();
    if(slen-tlen > 1)
        return false;
    else if(slen - tlen == 1){
        bool flag = false;
        for(int sp = 0, tp = 0; sp < slen && tp < tlen; sp++, tp++){
            if(s[sp] != t[tp]){
                if(!flag){
                    flag = true;
                    tp--;
                }
                else
                    return false;
            }
        }
        return true;
    }
    else if(slen - tlen == 0){
        bool flag = false;
        for(int sp = 0, tp = 0; sp < slen; sp++, tp++){
            if(s[sp]!=t[tp]){
                if(!flag)
                    flag = true;
                else
                    return false;
            }
        }
    }
    return flag;
}
