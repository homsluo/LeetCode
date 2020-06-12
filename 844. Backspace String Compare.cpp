//
// Created by homsl on 2020/4/9.
//
bool backspaceCompare(string S, string T) {
    if(S.empty() && T.empty())
        return true;
    int sp = S.size()-1;
    int tp = T.size()-1;
    int scount = 0;
    int tcount = 0;
    while(sp >= 0 || tp >= 0){
        while((sp >= 0 && S[sp] == '#') || (tp >= 0 && T[tp] == '#')){
            while(sp >= 0 && S[sp] == '#'){
                scount++;
                sp--;
            }
            while(tp >= 0 && T[tp] == '#'){
                tcount++;
                tp--;
            }
            while(sp >= 0 && S[sp] != '#' && scount){
                sp--;
                scount--;
            }
            while(tp >= 0 && T[tp] != '#' && tcount){
                tp--;
                tcount--;
            }
        }
        if(sp == -1 && tp == -1)
            return true;
        if(sp == -1 || tp == -1 || S[sp] != T[tp])
            return false;
        sp--;
        tp--;
    }
    return true;
}
