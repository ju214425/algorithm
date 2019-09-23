#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define INF 0x7fffffff

typedef long long ll;

struct Edge {
    int src, dst; ll cost; unsigned long key;
    bool operator > (const Edge &a) const {return cost > a.cost;} // for MIN_HEAP
    Edge operator + (const Edge &a) const {return {src, a.dst, cost+a.cost};} // for Edge NEW
};

struct Graph {
    int V;
    vector<vector<unsigned long>> adj, radj;
    vector<Edge> edges;
    
    Graph(int size) {
        V = size;
        adj.resize(size);
        radj.resize(size);
    }
    
    void push(int src, int dst, ll cost) {
        push(src, dst, cost, edges.size());
    }
    
    void push(int src, int dst, ll cost, unsigned long key) {
        adj[src].push_back(key);
        radj[dst].push_back(key);
        edges.push_back({src, dst, cost, key});
    }
    
    void update(unsigned long key, ll cost) {
        edges[key].cost = cost;
    }
};

struct Dijkstra: Graph {
    Dijkstra(int size): Graph(size) {}
    vector<ll> shortest_dist(int s) {
        vector<ll> dist(V, INF);
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        
        dist[s] = 0;
        pq.push({s, s, 0});
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            if (curr.cost > dist[curr.dst]) continue;
            for (auto idx: adj[curr.dst]) {
                auto next = edges[idx];
                Edge NEW = curr + next;
                if (dist[NEW.dst] > NEW.cost) {
                    dist[NEW.dst] = NEW.cost;
                    pq.push(NEW);
                }
            }
        }
        return dist;
    }
    
    Graph shortest_path(int s, int d) {
        auto dist = shortest_dist(s);
        Graph ret = V;
        
        queue<int> q; q.push(d);
        while (!q.empty()) {
            auto dst = q.front(); q.pop();
            for (auto idx: radj[dst]) {
                auto src = edges[idx].src;
                if (dist[src] + edges[idx].cost == dist[dst]) {
                    q.push(src);
                    ret.push(src, dst, edges[idx].cost, edges[idx].key);
                }
            }
        }
        
        return ret;
    }
};












struct Line{
	int x1, y1, x2, y2;
};

bool is_intersectX(Line l1, Line l2){
	if(l1.x1 < l2.x1 and l2.x1 < l1.x2) return true;
	if(l1.x1 < l2.x2 and l2.x2 < l1.x2) return true;
	return false;
}

bool is_intersectY(Line l1, Line l2){
	if(l1.y1 < l2.y1 and l2.y1 < l1.y2) return true;
	if(l1.y1 < l2.y2 and l2.y2 < l1.y2) return true;
	return false;
}

int dist(pair<int, int> a, pair<int, int> b){
	return ((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

int get_dist(Line l1, Line l2){
	pair<int, int> a,b,c,d;
	int d1, d2, d3, d4, d5, d6;
	d5 = d6 = 0x7fffffff;

	a = {l1.x1, l1.y1};
	b = {l1.x2, l1.y2};
	c = {l2.x1, l2.y1};
	d = {l2.x2, l2.y2};

	// cout << " a : " << l1.x1 << l1.y1
	// 	<< " b : " << l1.x2 << l1.y2
	// 	<< " c : " << l2.x1 << l2.y1
	// 	<< " d : " << l2.x2 << l2.y2
	// 	<< endl;
	

	d1 = dist(a, c);
	d2 = dist(a, d);
	d3 = dist(b, c);
	d4 = dist(b, d);
	int minimum = min(min(d1, d2), min(d3, d4));

	if(is_intersectX(l1, l2)){
		d5 = min(abs(l1.y1 - l2.y1), abs(l1.y1 - l2.y2));
		d5 *= d5;
	}
	if(is_intersectY(l1, l2)){
		d5 = min(abs(l1.x1 - l2.x1), abs(l1.x1 - l2.x2));
		d5 *= d5;
	}
	if(is_intersectX(l2, l1)){
		d6 = min(abs(l2.y1 - l1.y1), abs(l2.y1 - l1.y2));
		d6 *= d6;
	}
	if(is_intersectY(l2, l1)){
		d6 = min(abs(l2.x1 - l1.x1), abs(l2.x1 - l1.x2));
		d6 *= d6;
	}
	minimum = min(minimum, min(d5, d6));
	// cout << "min : " << minimum << endl;
	// cout << " d1 : " << d1 <<" d2 : " << d2 <<" d3 : " << d3 <<" d4 : " << d4 <<" d5 : " << d5 <<" d6 : " << d6 <<endl;
	return minimum;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int u, v, w, l;
	int x, y, x1, y1, x2, y2;
	int prev_x, prev_y;
	vector<Line> Up, Down, Island;
	
	cin >> n >> m;
	cin >> u >> v >> w >> l;

	cin >> prev_x >> prev_y;
	for(int i = 0 ; i < u-1 ; i++){
		cin >> x >> y;

		Down.push_back({prev_x, prev_y, x, y});
		prev_x = x;
		prev_y = y;
	}

	cin >> prev_x >> prev_y;
	for(int i = 0 ; i < v-1 ; i++){
		cin >> x >> y;
		if(x < prev_x){
			x1 = x;
			x2 = prev_x;
		}
		else{
			x1 = prev_x;
			x2 = x;
		}
		if(y < prev_y){
			y1 = y;
			y2 = prev_y;
		}
		else{
			y1 = prev_y;
			y2 = y;
		}
		Up.push_back({x1, y1, x2, y2});

		prev_x = x;
		prev_y = y;	
	}

	for(int i = 0 ; i < w ; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		Island.push_back({x1, y1, x2, y2});
	}

	Dijkstra d(w+2);

	int mini = INF;
	for(int i = 0 ; i < u-1 ; i++){
		for(int j = 0 ; j < v-1 ; j++){
			mini = min(mini, get_dist(Down[i], Up[j]));
		}
	}
	if(mini <= l){
		d.push(0, w+1, mini);
		// d.push(w+1, 0, mini);
	}

	for(int i = 0 ; i < w ; i++){
		int minimum = INF;
		for(int j = 0 ; j < u-1 ; j++){
			// cout << i+1 << " " << j << endl;
			minimum = min(minimum, get_dist(Down[j], Island[i]));
		}
		if(minimum <= l){
			d.push(0, i+1, minimum);
			// d.push(i+1, 0, minimum);
		}
	}

	for(int i = 0 ; i < w ; i++){
		int minimum = INF;
		for(int j = 0 ; j < v-1 ; j++){
			minimum = min(minimum, get_dist(Up[j], Island[i]));
		}
		if(minimum <= l){
			// d.push(w+1, i+1, minimum);
			d.push(i+1, w+1, minimum);
		}
	}

	for(int i = 0 ; i < w ; i++){
		for(int j = i ; j < w ; j++){
			if(get_dist(Island[i], Island[j]) <= l){
				d.push(i+1, j+1, get_dist(Island[i], Island[j]));
				// d.push(j+1, i+1, get_dist(Island[i], Island[j]));
			}
		}
	}


	if(d.shortest_dist(0)[w+1] == INF) cout << -1 << "\n";
	else cout << d.shortest_dist(0)[w+1] << "\n";

}