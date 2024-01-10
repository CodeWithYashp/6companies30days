class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> memo;
        return shopping_dp(price, special, needs, memo);
    }

private:
    string encode(const vector<int>& needs) {
        string key = "";
        for (int n : needs) {
            key += to_string(n) + ",";
        }
        return key;
    }

    int shopping_dp(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& memo) {
        string key = encode(needs);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int cost = 0;
        for (int i = 0; i < needs.size(); ++i) {
            cost += needs[i] * price[i];
        }

        for (vector<int>& s : special) {
            vector<int> new_needs(needs);
            bool valid_offer = true;

            for (int i = 0; i < needs.size(); ++i) {
                new_needs[i] -= s[i];
                if (new_needs[i] < 0) {
                    valid_offer = false;
                    break;
                }
            }

            if (valid_offer) {
                cost = min(cost, s.back() + shopping_dp(price, special, new_needs, memo));
            }
        }

        memo[key] = cost;
        return cost;
    }
};