#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int par[1005];
int level[1005];

struct Edge{
	ll a, b;
	double c;
};

struct Coord{
	ll x, y;
	int number;
};

bool cmp(Edge e1, Edge e2){
	return e1.c < e2.c;
}

void init(){
	for(int i = 1 ; i < 1005 ; i++){
		par[i] = i;
		level[i] = 1;
	}
}

int find(ll x){
	if(x == par[x])
		return x;
	return par[x] = find(par[x]);
}

void join(int x, int y){
	x = find(x);
	y = find(y);

	if(x == y)
		return;

	if(level[x] > level[y])
		swap(x, y);

	par[x] = y;

	if(level[x] == level[y])
		level[y]++;
}

int main(){
	int n, m;
	int x, y;
	double sum = 0.0, dist;
	int cnt = 0, i = 0;

	scanf("%d%d", &n, &m);
	vector<Coord> c;
	vector<Edge> e;

	init();

	for(int i = 1 ; i <= n ; i++){
		scanf("%d%d", &x ,&y);
		c.push_back({x, y, i});
	}

	for(int i = 0 ; i < m ; i++){
		int f, s;
		scanf("%d%d", &f, &s);
		if(find(f) != find(s)){
			join(f, s);
			cnt++;
		}
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = i ; j < n ; j++){
			dist = sqrt((c[i].x-c[j].x) * (c[i].x-c[j].x) + (c[i].y-c[j].y) * (c[i].y-c[j].y));
			e.push_back({c[i].number, c[j].number, dist});
		}
	}

	sort(e.begin(), e.end(), cmp);

	while(cnt != n-1){
		if(find(e[i].a) != find(e[i].b)){
			join(e[i].a, e[i].b);
			cnt++;
			sum += e[i].c;
		}
		i++;
	}

	printf("%.2lf\n", sum);
}