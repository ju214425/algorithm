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
		// if(level[x] > level[y]) 
		// 	swap(x, y);

		parent[x] = y;

		if(level[x] == level[y])
			++level[y];
	}
};

int main(){
	int n, m;
	int a, b, c;
	scanf("%d%d", &n, &m);
	UnionFind uf(n);
	uf.init();
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &a, &b, &c);
		if(a == 0){
			uf.join(b, c);
		}
		else{
			if(uf.find(b) == uf.find(c)){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}

	return 0;
}