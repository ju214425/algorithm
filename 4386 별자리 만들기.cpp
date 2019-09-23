#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int par[105];
int level[105];

struct Coord{
	double x, y;
	int number;
};

struct Edge{
	int a, b;
	double c;
};

bool cmp(Edge e1, Edge e2){
	return e1.c < e2.c;
}

void init(){
	for(int i = 0 ; i < 105 ; i++){
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

	int n;
	int cnt = 0, i = 0;
	double sum = 0.0;
	cin >> n;

	vector<Coord> c;
	vector<Edge> e;

	init();
	for(int i = 1 ; i <= n ; i++){
		double x, y;
		cin >> x >> y;
		c.push_back({x, y, i});
 	}

 	for(int i = 0 ; i < n ; i++){
 		for(int j = i ; j < n ; j++){
 			double dist = sqrt((c[i].x - c[j].x) * (c[i].x - c[j].x) + 
 				(c[i].y - c[j].y) * (c[i].y - c[j].y));
 			e.push_back({c[i].number, c[j].number, dist});
 		}
 	}

 	sort(e.begin(), e.end(), cmp);

 	while(cnt != n - 1){
 		if(find(e[i].a) != find(e[i].b)){
 			join(e[i].a, e[i].b);
 			cnt++;
 			sum += e[i].c;
 		}
 		i++;
 	}

 	cout << sum;
}