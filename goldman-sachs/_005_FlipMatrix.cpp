class Solution {
private:
    unordered_set<int> s;
    int rows, cols, total;
public:
    Solution(int m, int n) {
        rows = m;
        cols = n;
        total = m * n;
    }
    
    vector<int> flip() {
        if(s.size() == total){
            return {};
        }
        int i = rand() % total;
        while(s.count(i)){
            i = ++i % total;
        }
        s.insert(i);
        return { i / cols, i % cols};
    }
    
    void reset() {
        s = {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */