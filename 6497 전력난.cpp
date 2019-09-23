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
	int x, y, z;
	while(true){
		cin >> m >> n;
		if(n == 0 and m == 0) break;

		int total = 0, sum = 0, cnt = 0, i = 0;
		init();

		vector<Edge> E;

		for(int i = 0 ; i < n ; i++){
			cin >> x >> y >> z;
			E.push_back({x, y, z});
			total += z;
		}

		sort(E.begin(), E.end(), cmp);

		while(cnt != m-1){
			if(find(E[i].a) != find(E[i].b)){
				join(E[i].a, E[i].b);
				sum += E[i].c;
				cnt++;
			}
			i++;
		}

		cout << total - sum << "\n";
	}	
}