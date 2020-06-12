//
// Created by homsl on 2020/3/22.
//
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int size = gas.size();
    for(int i = 0; i < size; i++){
        if(gas[i] >= cost[i] && helper(i, i, gas, cost, 0, false))
            return i;
    }
    return -1;
}

bool helper(int start, int curr, vector<int>& gas, vector<int>& cost, int curgas, int flag){
    if(curr == start && flag)
        return true;;
    curgas = curgas+gas[curr]-cost[curr];
    if(curgas < 0)
        return false;

    curr = (curr+1)%gas.size();
    return helper(start, curr, gas, cost, curgas, true);
}

//-----------------------------------------------------------------------------------------------------------
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int size = gas.size();
    for(int i = 0; i < size; i++){
        if(gas[i] >= cost[i]){
            int curgas = 0;
            for(int j = 0; j < size; j++){
                int idx=(j+i)%size;
                curgas = curgas+gas[idx]-cost[idx];
                if(curgas < 0)
                    break;
            }
            if(curgas >= 0)
                return i;
        }
    }
    return -1;
}
//---------------------------------------------------------------------------------------------------

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int remain = 0;
    int debt = 0;
    int start = 0;

    for(int i = 0; i < gas.size(); i++){
        remain += gas[i] - cost[i];
        if(remain < 0){
            start = i+1;
            debt += remain;
            remain = 0;
        }
    }

    return remain+debt<0?-1:start;
}