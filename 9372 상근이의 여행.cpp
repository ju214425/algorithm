#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int par[1005];
int level[1005];

struct Edge{
	int a, b;
};

void init(){
	for(int i = 0 ; i < 1005 ; i++){
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

	int t;
	int n, m;
	int a, b;
	cin >> t;

	while(t--){
		cin >> n >> m;
		// vector<Edge> E;
		// int cnt = 0, i = 0;

		// init();

		for(int i = 0 ; i < m ; i++){
			cin >> a >> b;
			// E.push_back({a, b});
		}
		
		// while(cnt != n-1){
		// 	if(find(E[i].a) != find(E[i].b)){
		// 		join(E[i].a, E[i].b);
		// 		cnt++;
		// 	}
		// 	i++;
		// }

		// cout << cnt << "\n";
		cout << n-1 << "\n";
	}
}