//
// Created by homsl on 2020/4/13.
//
class TwoSum{
private:
    unordered_map<int, int> map;
public:
    TwoSum(){

    }

    void add(int num){
        map[num]++;
    }

    bool find(int val){
        for(auto it:map){
            int num1 = it->first;
            int num2 = val-num1;
        }
        if(num1 == num2)
            return (map[num2]>1);
        else
            return map.count(num2);
    }
};
