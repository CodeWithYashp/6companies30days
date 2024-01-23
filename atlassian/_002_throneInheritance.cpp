class ThroneInheritance {
private:
    unordered_map<string, vector<string>> child;
    vector<string> s;
    unordered_set<string> dead;
    string king;
    
    void solve(string m) {
        if (!dead.count(m)) s.push_back(m);
        for (auto c : child[m])
            solve(c);
    }
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        child[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        s = {};
        solve(king);
        return s;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */