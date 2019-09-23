#include <iostream>
#include <vector>

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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		
	int n, m;
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		
	}

}