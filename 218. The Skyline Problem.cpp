//
// Created by homsl on 2020/5/21.
//
// Use Multiset library
class Solution {
private:
    multiset<int>hs_;
    int maxHeight() const{
        if(hs_.empty()) return 0;
        return *hs_.rbegin();   // return max height in the set
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Sweep line algo.
        // Using multiset to keep tracking top and insert and remove
        typedef pair<int, int> Event;   // (Li/Ri, Hi)
        vector<Event> es;
        hs_.clear();

        for(const auto& b:buildings){
            // Use emplace_back can reduce "move" and "copy" by use "push_back"
            // If its a leave event, mark the height as negative, easy to see
            es.emplace_back(b[0], b[2]);
            es.emplace_back(b[1], -b[2]);
        }

        // To avoid edge cases by sort
        // if enter at same x, process higher first
        // if leave at same x, process lower first
        // if leave and enter at same time, process enter first
        sort(es.begin(), es.end(), [](const Event& e1, const Event& e2){
            // 1.Enter same x, higer one first
            // 2.Leave same x, (- lower one) > (- higher one)
            // 3.Leave and Enter same x, (Enter one) > (- Leave one)
            if(e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });

        vector<vector<int>> ans; // Points Results

        for(const auto& e:es) {
            int x = e.first;
            bool entering = e.second > 0;
            int h = abs(e.second);

            // Sweep line algo.
            if(entering){
                if(h > this->maxHeight())
                    ans.push_back({x,h});
                hs_.insert(h);
            }
            else {
                hs_.erase(hs_.equal_range(h).first);  // Remove any one of height h
                if(h > this->maxHeight())   // If max height change, add point to ans
                    ans.push_back({x, this->maxHeight()});
            }
        }

        return ans;
    }
};

// Applied Max_Heap: Add-O(n), Remove-O(n)
class Solution {
private:
    struct Event{
        int id;
        int x;
        int h;
        int type;

        bool operator>(const Event& e) const {
            if(x == e.x){
                return h * type > e.h * e.type;
            }
            return x < e.x;
        }
    };

    class MaxHeap {
    private:
        vector<pair<int,int>> vals_;
        vector<int> idx_;
        int size_;

        void SwapNode(int i, int j){
            if(i == j)
                return;
            std::swap(idx_[vals_[i].second], idx_[vals_[j].second]);
            std::swap(vals_[i], vals_[j]);
        }

        void HeapifyUp(int i){
            while(i != 0){
                int p = (i-1)/2;
                if(vals_[i].first <= vals_[p].first)
                    return;
                SwapNode(i, p);
                i = p;
            }
        }

        void HeapifyDown(int i){
            while(true){
                int c1 = i*2+1;
                int c2 = i*2+2;

                if(c1 >= size_) return;

                int c = (c2 <size_ &&
                        vals_[c2].first > vals_[c1].first) ? c2 : c1;

                if(vals_[c].first <= vals_[i].first)
                    return;
                SwapNode(c, i);
                i = c;
            }
        }

    public:
        MaxHeap(int max_items): vals_(max_items), idx_(max_items, -1), size_(0){}

        void Add(int height, int id){
            idx_[id] = size_;
            vals_[size_] = {height, id};
            size_++;
            HeapifyUp(idx_[id]);
        }

        void Remove(int id){
            int idx_to_evict = idx_[id];
            SwapNode(idx_to_evict, size_-1);
            size_--;
            HeapifyDown(idx_to_evict);
        }

        bool Empty() const{
            return size_==0;
        }

        int Max() const{
            return Empty() ? 0 : vals_.front().first;
        }
    };

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings){
        vector<Event> events;
        int id = 0;
        for(const auto& b:buildings){
            events.push_back({id, b[0], b[2], 1});
            events.push_back({id, b[1], b[2], -1});
            id++;
        }

        sort(events.begin(), events.end());

        MaxHeap heap(buildings.size());

        vector<vector<int>> ans;

        for(const auto& event:events){
            int x = event.x;
            int h = event.h;
            int id = event.id;
            int type = event.type;

            if(type == 1){
                if(h > heap.Max())
                    ans.push_back({x, h});
                heap.Add(h, id);
            }
            else{
                heap.Remove(id);
                if(h > heap.Max())
                    ans.push_back({x, heap.Max()});
            }
        }
        return ans;
    }
};