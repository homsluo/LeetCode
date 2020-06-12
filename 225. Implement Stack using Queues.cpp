//
// Created by homsl on 2020/5/26.
//
class MyStack {
private:
    queue<int> q;
    int size_;
public:
    /** Initialize your data structure here. */
    MyStack() {
        q = queue<int>();
        size_ = 0;
    }

    /** Push element x onto stack. */
    void push(int x) {
        size_++;
        q.push(x);
        if(size_ > 1){
            int k = size_-1;
            while(k--){
                q.push(q.front());
                q.pop();
            }
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q.front();
        size_--;
        q.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
