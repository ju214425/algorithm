#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <vector>

#define INF 0x7fffffff

using namespace std;

typedef long long ll;

struct Edge {
    int src, dst, weight;
    bool operator > (const Edge &a) const {return weight > a.weight;} // for MIN_HEAP
    Edge operator + (const Edge &a) const {return {src, a.dst, weight+a.weight};} // for Edge NEW
};

struct Graph {
    int V;
    vector<unordered_map<int, Edge> > adj;
    vector<vector<int> > back_track;
    Edge query(int s, int d) {
        if (s == d) return {s, d, 0};
        return adj[s].count(d) ? adj[s][d] : (Edge) {s, d, INF};
    }
    void update(int s, int d, int w) {
        adj[s][d] = {s, d, w};
        back_track[d].push_back(s); 
    }
    void update(Edge e) {
        adj[e.src][e.dst] = e;
        back_track[e.dst].push_back(e.src); 
    }
};

struct Dijkstra: Graph {
    Dijkstra(int size) {
        V = size;
        adj.resize(size);
        back_track.resize(size);
    }
    
    auto dijkstra(int s) {
        vector<int> dist(V, INF);
        priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
        dist[s] = 0;
        pq.push({s, s, 0});
        for (;!pq.empty();) {
            auto curr = pq.top();
            // curr == {s, curr.dst, curr.weight}
            pq.pop();
            if (curr.weight > dist[curr.dst]) continue;
            for (auto dstedge: adj[curr.dst]) {
                auto next = dstedge.second;
                // next == {curr.dst, next.dst, next.weight}
                Edge NEW = curr + next;
                // Edge NEW = {curr.src, next.dst, curr.weight + next.weight};
                
                if (dist[NEW.dst] < NEW.weight) continue;
                if (dist[NEW.dst] == NEW.weight) continue;
                dist[NEW.dst] = NEW.weight;
                pq.push(NEW);
            }
        }
        return dist;
    }
    
    int dijkstra(int s, int d) {
        return dijkstra(s)[d];
    }
};
    

int main(){
	int n, m;
	int x, y, z;
	cin >> n >> m;

	Dijkstra d(n+1);
	for(int i = 0 ; i < m ; i++){
		cin >> x >> y >> z;
		d.update({x, y, z});
	}

	auto dist = d.dijkstra(1);

	
}