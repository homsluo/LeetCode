//
// Created by homsl on 2020/4/14.
//
string stringShift(string s, vector<vector<int>>& shift) {
    if(shift.empty())
        return s;
    for(vector<int>& ops:shift){
        doShift(ops, s);
    }
    return s;
}

void doShift(vector<int>& ops, string& s){
    int dir = ops[0];
    int size = s.size();
    int amt = ops[1]%size;
    if(!dir){
        // left shift
        string temp = s.substr(0, amt);
        s = s.substr(amt);
        s += temp;
    }
    else{
        //right shift
        string temp = s.substr(size-amt);
        s = s.substr(0, size-amt);
        s = temp+s;
    }
}
