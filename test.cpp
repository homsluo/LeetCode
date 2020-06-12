//
// Created by homsl on 2019/6/18.
//
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <regex>
#include <list>
#include <deque>
#include <numeric>
#include <ctime>
#include <random>
bool cmp(std::vector<int>& a,std::vector<int>& b){
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

class Entity{
public:
    int x, y;
    Entity(){
        std::cout << "Entity Constructed" << std::endl;
    }

    ~Entity(){
        std::cout << "Entity Destructed" << std::endl;
    }
};

class Player : public Entity{
public:
    const char* Name;

    Player(const char* name){
        Name = name;
        std::cout << "Player Constructed" << std::endl;
    }

    ~Player(){
        std::cout << "Player Destructed" << std::endl;
    }

    void PrintName(){
        std::cout << "Player's Name is : " << Name << std::endl;
    }
};

void func(){
    Entity* e1;
    Player* p1 = new Player("homs");
    e1 = p1;
    delete p1;
}

void func1(Entity& e1){

}
int main(){
    Player p1("homs");
    Entity e1;
    func1(p1);
    std::cout << "finished" << '\n';

    auto i = nullptr;
    i = "asdf";
}
/*
k: 1
j: 0
i: 0
2 0 2 1 1 0
0 2
*/