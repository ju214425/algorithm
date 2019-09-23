#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

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
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int cnt = 0;
	UnionFind uf(n);
	uf.init();
	for(int i = 1 ; i <= m ; i++){
		int c1, c2;
		scanf("%d%d", &c1, &c2);
		uf.join(c1, c2);
	}
	int parent = uf.find(1);
	for(int i = 2 ; i <= n ; i++){
		if(uf.find(i) == parent) cnt++;
	}

	printf("%d", cnt);
}