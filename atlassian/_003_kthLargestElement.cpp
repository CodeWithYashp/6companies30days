class KthLargest {
private:
    int largest;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->largest = k;
        for(auto num : nums){
            this->pq.push(num);
        }
    }
    
    int add(int val) {
        pq.push(val);

        int a = pq.size() - largest;

        while(a > 0){
            pq.pop();
            a--;
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */