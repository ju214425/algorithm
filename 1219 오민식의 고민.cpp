#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 0x6fffffffffffffff

using namespace std;

typedef long long ll;

struct Edge {
    int src, dst; ll cost;
    bool operator > (const Edge &a) const {return cost > a.cost;} // for MIN_HEAP
    Edge operator + (const Edge &a) const {return {src, a.dst, cost+a.cost};} // for Edge NEW
};

struct Graph {
    int V;
    vector<vector<unsigned long>> adj;
    vector<Edge> edges;
    
    Graph(int size) {
        V = size;
        adj.resize(size);
    }
    
    void push(Edge e) {
        adj[e.src].push_back(edges.size());
        edges.push_back(e);
    }
};

struct SPFA: Graph {
    vector<ll> dist;
    vector<bool> called;
    SPFA(int size): Graph(size),dist(size, INF){}
    vector<ll> shortest_path(int s) {
        vector<ll> dist = this->dist;
        vector<int> cnt(V, 0);
        vector<bool> inq(V, 0);
        queue<int> q;
        
        dist[s] = 0;
        q.push(s);
        inq[s] = 1;
        while (!q.empty()) {
            int src = q.front();
            q.pop();
            inq[src] = 0;
            for (auto idx: adj[src]) {
                auto e = edges[idx];
                int dst = e.dst;
                ll cost = e.cost;
                if (cnt[dst] == V) {
                    // negative cycle!
                    dist[dst] = -INF;
                } else if (dist[dst] > dist[src] + cost) {
                    dist[dst] = dist[src] + cost;
                    if (!inq[dst]) {
                        cnt[dst]++;
                        q.push(dst);
                        inq[dst] = 1;
                    }
                }
            }
        }
        this->dist = dist;
        called.resize(V);
        for (int i = 0; i < V; ++i) {
            if (dist[i] == -INF)
                dfs(i);
        }
        return this->dist;
    }
    
    void dfs(int s) {
        if (called[s]) return;
        called[s] = 1;
        dist[s] = -INF;
        for (auto idx: adj[s])
            dfs(edges[idx].dst);
    }
};


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, s, t, m;
	int begin, end, price;
	cin >> n >> s >> t >> m;

	SPFA g(n);
	for(int i = 0 ; i < m ; i++){
		cin >> begin >> end >> price;
		g.push({begin, end, price});
	}
	vector<ll> v(n);
	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
	}
	vector<ll> dist = g.shortest_path(s);
	if(dist[t] == INF) cout << "gg\n";
	else if(dist[t] == -INF) cout << "Gee\n";
}