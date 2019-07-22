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
		for(ll i = 0 ; i <= size ; i++){
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
		
		// if(level[x] > level[y]) 
		// 	swap(x, y);

		parent[x] = y;

		if(level[x] == level[y])
			++level[y];

	}
};


int main(){
	int g, p, ans = 0;
	scanf("%d%d", &g, &p);
	UnionFind uf(g);
	uf.init();

	for(int i = 1 ; i <= p ; i++){
		int temp, g1;
		scanf("%d", &temp);
		g1 = uf.find(temp);
		
		if(g1 != 0){
			uf.join(g1, g1-1);
			ans++;
		}
		else break;
	}

	printf("%d\n", ans);
}