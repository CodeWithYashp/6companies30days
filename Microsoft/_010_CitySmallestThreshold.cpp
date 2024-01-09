class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];

        for(auto edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});

            adj[edge[1]].push_back({edge[0], edge[2]});

        }
        int cnt = INT_MAX, city = -1;

        for(int i = 0; i < n; i++){
            vector<int> distance(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            pq.push({0, i});

            distance[i] = 0;

            while(!pq.empty()){
                pair<int, int> p = pq.top();
                pq.pop();

                int node = p.second;
                int cost = p.first;

                if(distance[node] < cost)   continue;

                for(auto it : adj[node]){
                    int to = it.first;
                    int wt = it.second;

                    if(distance[to] > distance[node] + wt){
                        distance[to] = distance[node] + wt;
                        pq.push({distance[to], to});
                    }
                }
            }
            int count = 0; 
            for(auto it: distance){
                if(it <= distanceThreshold) count++;
            }

            if(count <= cnt){
                cnt = count;
                city = i;
            }
        }

        return city;
    }
};