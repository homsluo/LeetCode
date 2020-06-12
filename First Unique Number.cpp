//
// Created by homsl on 2020/4/28.
//
/* You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.

 Example 1:

Input:
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output:
[null,2,null,2,null,3,null,-1]

Explanation:
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1
*/

class FirstUnique {
private:
    unordered_map<int, list<int>::iterator> count;
    list<int> list;
public:
    FirstUnique(vector<int>& nums) {
        for(int num:nums){
            if(count.count(num)){
                auto it = count[num];
                if(it != list.end()){
                    list.erase(it);
                    count[num] = list.end();
                }
                continue;
            }
            list.push_back(num);
            count[num] = --list.end();
        }
    }

    int showFirstUnique() {
        if(list.size() > 0)
            return list.front();
        return -1;
    }

    void add(int value) {
        if(count.count(value)){
            auto it = count[value];
            if(it != list.end()){
                list.erase(it);
                count[value] = list.end();
            }
        }
        else{
            list.push_back(value);
            count[value] = --list.end();
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */