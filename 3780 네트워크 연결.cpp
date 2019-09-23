#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct UnionFind{
	ll size;
	vector<ll> parent;
	vector<ll> dist;

	UnionFind(ll size){
		this->size = size;
		parent.resize(size+1);
		dist.resize(size+1);
	}

	void init(){
		for(ll i = 1 ; i <= size ; i++){
			parent[i] = i;
			dist[i] = 0;
		}
	}

	ll find(ll x){
		if(parent[x] == x)
			return x;
		else{
			ll temp = find(parent[x]);
			dist[x] += dist[parent[x]];
			parent[x] = temp;
			return temp;
		}
	}

	void join(ll x, ll y){
		parent[x] = y;
		dist[x] = abs(x-y)%1000;
	}

	ll query(ll x){
		return dist[x];
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n;
	char c;
	cin >> t;
	while(t--){
		cin >> n;
		UnionFind uf(n);
		uf.init();
		while(true){
			cin >> c;
			int company1, company2;
			if(c == 'E'){
				cin >> company1;
				uf.find(company1);
				cout << uf.query(company1) << "\n";
			}
			else if(c == 'I'){
				cin >> company1 >> company2;
				uf.join(company1, company2);
			}
			else{
				break;
			}
		}
	}
}