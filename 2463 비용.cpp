#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000000

typedef long long ll;



struct UnionFind{
	ll size;
	vector<ll> parent;
	vector<ll> level;

	UnionFind(ll size){
		this->size = size;
		parent.resize(size+1);
		level.resize(size+1);
	}

	void init(){
		for(ll i = 1 ; i <= size ; i++){
			parent[i] = i;
			level[i] = 1;
		}
	}

	ll find(ll x){
		if(parent[x] == x)
			return x;	
		return parent[x] = find(parent[x]);
	}

	void join(ll x, ll y){
		x = find(x);
		y = find(y);
		if(x == y) 
			return;
		if(level[x] > level[y]) 
			swap(x, y);

		parent[x] = y;

		if(level[x] == level[y])
			++level[y];
	}

	bool same_set(ll x, ll y){
		return find(x) == find(y);
	}
};

struct Vertex{
	int x, y, w;
};

bool cmp(Vertex &v1, Vertex &v2){
	return v1.w > v2.w;
}

void print(vector<Vertex> &v1){
	for(int i = 1 ; i < v1.size() ; i++){
		printf("%d ", v1[i].w);
	}
}

int main(){
	int n, m;
	int x, y, w;
	int cost = 0;
	scanf("%d%d", &n, &m);
	vector<Vertex> v(m+1);
	UnionFind uf(m+1);

	for(int i = 1 ; i <= m ; i++){
		scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].w);
		cost += v[i].w;
	}
	printf("%d", cost);
	sort(v.begin()+1, v.end(), cmp);

	for(int i = 1 ; i <= m ; i++){
		
	}

	printf("%d", cost);

}