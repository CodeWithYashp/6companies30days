class Solution {
private:
    int getmax(int mask, vector<vector<int>>& graph) {
        int maxd = -1;
        
        for (int i = 0; i < 15; i++) {
            if (mask & (1 << i)) {
                maxd = max(maxd, dfs(i, graph, mask));
            }
        }
        return maxd;
    }

    int dfs(int node, vector<vector<int>>& graph, int mask) {
        queue<int> q;
        q.push(node);
        int dist = -1;
        int curr = mask;
        
        while (!q.empty()) {
            dist++;

            for (int l = q.size() - 1; l >= 0; l--) {
                int z1 = q.front();
                curr = curr ^ (1 << z1);
                q.pop();

                for (int z : graph[z1]) {
                    if (((mask & (1 << z)) != 0) && ((curr & (1 << z)) != 0)) {
                        q.push(z);
                    }
                }
            }
        }

        if (curr != 0) {
            return -1;
        }

        return dist;
    }


public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> res(n - 1, 0);
        vector<vector<int>> graph(n, vector<int>());
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for (int mask = 0; mask < (1 << n); mask++) {
            int d = getmax(mask, graph);
            
            if (d > 0) {
                res[d - 1]++;
            }
        }
        return res;  
    }
};