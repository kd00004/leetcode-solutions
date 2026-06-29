class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& edge : edges){
            int u=edge[0], v=edge[1], w=edge[2];
            adj[u].push_back({v, w});
        }
        const int inf=1e9;
        // dist[node][consecutive_count]
        vector<vector<int>> dist(n, vector<int>(k+1, inf));

        // (distance, node, consecutive_count)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int d = curr[0];
            int u = curr[1];
            int count = curr[2];

            if(d > dist[u][count]) continue;

            if(u == n-1) return d;

            for(const auto& neighbour : adj[u]){
                int v = neighbour.first;
                int weight = neighbour.second;

                int next_count = (labels[u] == labels[v]) ? (count+1):1;
                if(next_count <= k){
                    if(d + weight < dist[v][next_count]){
                        dist[v][next_count] = d + weight;
                        pq.push({dist[v][next_count], v, next_count});
                    }
                }
            }
        }
        return -1;
    }
};