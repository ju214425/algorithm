#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int par[200005];
int level[200005];

struct Edge{
	int a, b, c;
};

bool cmp(Edge e1, Edge e2){
	return e1.c < e2.c;
}

void init(){
	for(int i = 0 ; i < 200005 ; i++){
		par[i] = i;
		level[i] = 1;
	}
}

int find(int x){
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b, c;
	int cnt = 0, sum = 0, i = 0;
	vector<Edge> E;

	init();
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		cin >> a >> b >> c;
		E.push_back({a, b, c});
	}

	sort(E.begin(), E.end(), cmp);
	
	cout << n-1 << "\n";

	while(cnt != n-1){
		if(find(E[i].a) != find(E[i].b)){
			join(E[i].a, E[i].b);
			cnt++;
			sum += E[i].c;
			cout << E[i].a << " " << E[i].b << "\n";
		}
		i++;
	}
}