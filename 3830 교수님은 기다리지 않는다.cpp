#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct UnionFind{
	ll size;
	vector<ll> parent;
	vector<ll> weight;

	UnionFind(ll size){
		this->size = size;
		parent.resize(size+1);
		weight.resize(size+1);
	}

	void init(){
		for(ll i = 1 ; i <= size ; i++){
			parent[i] = i;
			weight[i] = 0;
		}
	}

	ll find(ll x, ll w){
		if(parent[x] == x)
			return x;	
		return parent[x] = find(parent[x], w + weight[x]);

	}

	void join(ll x, ll y, ll w){
		x = find(x);
		y = find(y);
		if(x == y) 
			return;

		if(x < y)
			swap(x, y);

		parent[x] = y;

		weight[x] += (parent[x] + w);

	}

	bool same_set(ll x, ll y){
		return find(x) == find(y);
	}

	ll difference(ll x, ll y){
		weight
	}
};

int main(){
	int n, m;
	while(true){
		scanf("%d%d", &n, &m);
		if(n == 0 and m == 0) break;
		UnionFind uf(m);
		uf.init();
		for(int i = 0 ; i < m ; i++){
			char cmd;
			int a, b, w;
			scanf("%c", &c);
			if(c == '!'){
				scanf("%d%d%d", &a, &b, %w);
				uf.join(a, b, w);
			}
			else if(c == '?'){
				scanf("%d%d", &a, &b);
				if(!uf.same_set(x, y)) printf("UNKNOWN\n");
				else{

				}
			}
		}
	}
}