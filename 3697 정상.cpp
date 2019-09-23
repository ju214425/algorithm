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

int h[501][501];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, m, d;
	cin >> t;
	while(t--){
		cin >> n >> m >> d;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cin >> h[i][j];
			}
		}


	}
}