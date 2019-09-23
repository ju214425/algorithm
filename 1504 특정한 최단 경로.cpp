#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

#define INF 9876543210123

typedef long long ll;

struct Edge {
    ll src, dst, weight;
    bool operator > (const Edge &a) const {return weight > a.weight;} // for MIN_HEAP
    Edge operator + (const Edge &a) const {return {src, a.dst, weight+a.weight};} // for Edge NEW
};

struct Graph {
    ll V; 
    vector<unordered_map<ll, Edge> > adj;
    Edge query(ll s, ll d) {
        if (s == d) return {s, d, 0};
        return adj[s].count(d) ? adj[s][d] : (Edge) {s, d, INF};
    }
    void update(ll s, ll d, ll w) {
        adj[s][d] = {s, d, w};
    }
    void update(Edge e) {
        adj[e.src][e.dst] = e;
    }
};

struct Dijkstra: Graph {
    Dijkstra(ll size) {
        V = size;
        adj.resize(size);
    }
    
    auto dijkstra(ll s) {
        vector<ll> dist(V, INF);
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
    
    ll dijkstra(int s, int d) {
        return dijkstra(s)[d];
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, e;
    ll a, b, c;
    ll must1, must2;

    cin >> n >> e;

    Dijkstra D(n+1);

    for(int i = 0 ; i < e ; i++){
        cin >> a >> b >> c;
        D.update({a,b,c}); D.update({b,a,c});
    }
    cin >> must1 >> must2;

    ll cmp1 = D.dijkstra(1,must1) + D.dijkstra(must1, must2) + D.dijkstra(must2, n);
    ll cmp2 = D.dijkstra(1,must2) + D.dijkstra(must2, must1) + D.dijkstra(must1, n);

    if(cmp1 > INF or cmp2 > INF) cout << "-1\n";
    else{
        cout << min(cmp1, cmp2);
    }
    
}