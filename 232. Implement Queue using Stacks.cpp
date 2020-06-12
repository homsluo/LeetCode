//
// Created by homsl on 2020/5/27.
//
class MyQueue {
private:
    stack<int> stk_bot;
    stack<int> stk_top;
    int size_;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        stk_bot = stack<int>();
        stk_top = stack<int>();
        size_ = 0;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk_bot.push(x);
        size_++;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stk_top.empty()){
            for(int i = size_; i > 1; i--){
                stk_top.push(stk_bot.top());
                stk_bot.pop();
            }
            size_ = 0;
            int res = stk_bot.top();
            stk_bot.pop();
            return res;
        }
        int res = stk_top.top();
        stk_top.pop();
        return res;
    }

    /** Get the front element. */
    int peek() {
        if(stk_top.empty()){
            for(int i = size_; i > 0; i--){
                stk_top.push(stk_bot.top());
                stk_bot.pop();
            }
            size_ = 0;
        }
        return stk_top.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (stk_top.empty() && stk_bot.empty());
    }
};
