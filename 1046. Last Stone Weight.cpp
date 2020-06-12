//
// Created by homsl on 2020/4/12.
//
int lastStoneWeight(vector<int>& stones) {
    if(stones.empty())
        return 0;
    map<int, int> map;
    for(int num:stones){
        map[num]++;
    }
    while(!map.empty() && !(map.size() == 1 && map.begin()->second == 1)){
        auto it1 = --map.end();
        auto it2 = it1;
        int num1, num2;
        if(it1->second){
            num1 = it1->first;
            it1->second--;
        }
        else{
            num1 = (--it1)->first;
            it1->second--;
        }
        if(it2->second){
            num2 = it2->first;
            it2->second--;
        }
        else{
            num2 = (--it2)->first;
            it2->second--;
        }
        if(num1 != num2){
            map[abs(num1-num2)]++;
        }
        if(it1 == it2){
            if(!it1->second)
                map.erase(it1);
        }
        else{
            if(!it1->second)
                map.erase(it1);
            if(!it2->second)
                map.erase(it2);
        }
    }
    return map.empty()? 0 : map.begin()->first;
}
