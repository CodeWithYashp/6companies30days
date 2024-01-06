class DataStream {
public:
    unordered_map<int, int> freq;
    queue<int> q;
    int K;
    int temp;
    DataStream(int value, int k) {
        K = k;
        temp = value;
    }
    
    bool consec(int num) {
        q.push(num);
        freq[num]++;
        if(q.size() >= K){
            if(q.size() > K){
                freq[q.front()]--;
                if(freq[q.front()] == 0){
                    freq.erase(q.front());
                }
                q.pop();
            }
            if(freq.size() == 1 && freq[temp] > 0){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
};