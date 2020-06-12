//
// Created by homsl on 2020/3/28.
//
class LRUCache {
private:
    int cap;
    list <pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        const auto it = map.find(key);
        if(it == map.end())
            return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        const auto it = map.find(key);
        if(it != map.end()){
            // Already exist, update value;
            cache.splice(cache.begin(), cache, it->second);
            it->second->second = value;
            return;
        }

        if(cache.size() == cap){
            auto node = cache.back();
            map.erase(node.first);
            cache.pop_back();
        }
        cache.emplace_front(key, value);
        map[key] = cache.begin();
    }
};
