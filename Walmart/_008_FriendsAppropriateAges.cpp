class Solution {
private:

    bool requestAllowed(int ageA, int ageB) {
        return !(ageB <= 0.5 * ageA + 7 || ageB > ageA || (ageB > 100 && ageA < 100));
    }

public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> ageCount;
    
        for (int age : ages) {
            ageCount[age]++;
        }
        
        int requests = 0;
        
        for (auto a : ageCount) {
            for (auto b : ageCount) {
                if (requestAllowed(a.first, b.first)) {
                    requests += a.second * (b.second - (a.first == b.first ? 1 : 0));
                }
            }
        }
        
        return requests;    
    }
};