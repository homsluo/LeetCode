//
// Created by homsl on 2020/4/7.
//
class MinStack {
private:
    vector<int> stk;
    map<int, int> minv;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        minv[x]++;
        stk.push_back(x);
    }

    void pop() {
        minv[stk.back()]--;
        stk.pop_back();
    }

    int top() {
        return stk.back();
    }

    int getMin() {
        for(auto it:minv){
            if(it.second)
                return it.first;
        }
        return -1;
    }
};

// 2 Stack

class MinStack {
private:
    stack<int> stk;
    stack<int> stk_min;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(stk_min.empty() || x <= stk_min.top())
            stk_min.push(x);
        stk.push(x);
    }

    void pop() {
        if(stk.top() == stk_min.top())
            stk_min.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return stk_min.top();
    }
};
