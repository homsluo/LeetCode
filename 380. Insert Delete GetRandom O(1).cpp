//
// Created by homsl on 2019/8/30.
//
class RandomizedSet {
private:
    vector<int> set;
    unordered_map<int, int> map;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) == map.end()){
            set.emplace_back(val);
            map[val] = set.size()-1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) != map.end()){
            int last = set.back();
            map[last] = map[val];
            set[map[val]] = last;
            set.pop_back();
            map.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int res = rand()%set.size();
        return set[res];
    }
};
