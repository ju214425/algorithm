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

struct land{
	ll x1, y1, x2, y2;
	ll s;
	int index;
};

bool cmpx(land l1, land l2){
	return l1.x1 == l2.x1 ? l1.y1 < l2.y1 : l1.x1 < l2.x1;
}

bool cmpy(land l1, land l2){
	return l1.y1 == l2.y1 ? l1.x1 < l2.x1 : l1.y1 < l2.y1;
}

int main(){
	int n;
	scanf("%d", &n);
	ll result = 0;
	int p;
	vector<land> v(n+1);
	vector<ll> xpos, ypos, ans(n+1);
	UnionFind uf(n);
	uf.init();
	
	for(int i = 1 ; i <= n ; i++){
		ll x1, y1, w, h;
		scanf("%lli %lli %lli %lli", &x1, &y1, &w, &h);
		v[i].x1 = x1;
		v[i].y1 = y1;
		v[i].x2 = x1 + w;
		v[i].y2 = y1 + h;
		v[i].s = w*h;
		v[i].index = i;
		xpos.push_back(x1);
		xpos.push_back(x1+w);
		ypos.push_back(y1);
		ypos.push_back(y1+h);
	}
	
	sort(xpos.begin(), xpos.end());
	sort(ypos.begin(), ypos.end());
	xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
	ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());

	for(int i = 1 ; i <= n ; i++){
		v[i].x1 = (ll)(lower_bound(xpos.begin(), xpos.end(), v[i].x1) - xpos.begin())+1;
		v[i].x2 = (ll)(lower_bound(xpos.begin(), xpos.end(), v[i].x2) - xpos.begin())+1;
		v[i].y1 = (ll)(lower_bound(ypos.begin(), ypos.end(), v[i].y1) - ypos.begin())+1;
		v[i].y2 = (ll)(lower_bound(ypos.begin(), ypos.end(), v[i].y2) - ypos.begin())+1;

	}
	sort(v.begin()+1, v.end(), cmpx);
	for(int i = 1 ; i <= n ; i++){
		p = i;
		while(p <= n){
			if(v[i].x2 == v[p].x1){
				if((v[i].y1 <= v[p].y1 and v[p].y1 <= v[i].y2) 
					or (v[i].y1 <= v[p].y2 and v[p].y2 <= v[i].y2)
					or (v[p].y1 <= v[i].y1 and v[i].y1 <= v[p].y2)
					or (v[p].y1 <= v[i].y2 and v[i].y2 <= v[p].y2)){
					uf.join(v[i].index, v[p].index);
				}
			}
			if(v[i].x2 < v[p].x1){
				break;
			}
			p++;
		}
	}

	sort(v.begin()+1, v.end(), cmpy);
	for(int i = 1 ; i <= n ; i++){
		p = i;
		while(p <= n){
			if(v[i].y2 == v[p].y1){
				if((v[i].x1 <= v[p].x1 and v[p].x1 <= v[i].x2) 
					or (v[i].x1 <= v[p].x2 and v[p].x2 <= v[i].x2)
					or (v[p].x1 <= v[i].x1 and v[i].x1 <= v[p].x2)
					or (v[p].x1 <= v[i].x2 and v[i].x2 <= v[p].x2)){
					uf.join(v[i].index, v[p].index);
				}
			}
			if(v[i].y2 < v[p].y1){
				break;
			}
			p++;
		}
	}
	
	for(int i = 1 ; i <= n ; i++){
		int idx = uf.find(v[i].index);
		ans[idx] += v[i].s;
		result = max(result, ans[idx]);
	}
	
	printf("%lli", result);
}