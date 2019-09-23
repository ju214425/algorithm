#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

struct UnionFind{
	ll size;
	vector<ll> parent;
	vector<ll> level;
	vector<ll> child;

	UnionFind(ll size){
		this->size = size;
		parent.resize(size+1);
		level.resize(size+1);
		child.resize(size+1);
	}

	void init(){
		for(ll i = 1 ; i <= size ; i++){
			parent[i] = i;
			level[i] = 1;
			child[i] = 1;
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
		
		ll val = child[x] + child[y];
		child[x] = val;
		child[y] = val;
	}

	ll get_num(ll x){
		return child[find(x)];
	}

};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, f;
	
	cin >> t;
	while(t--){
		ll cnt = 1;
		cin >> f;
		UnionFind uf(f+1);
		uf.init();
		map<string, int> m;
		for(int i = 1 ; i <= f ; i++){
			string f1, f2;
			cin >> f1 >> f2;
			if(!m.count(f1)){
				m[f1] = cnt;
				cnt++;
			}
			if(!m.count(f2)){
				m[f2] = cnt;
				cnt++;
			}
			uf.join(m[f1], m[f2]);
			cout << uf.get_num(m[f1]) << "\n";
		}
	}
}