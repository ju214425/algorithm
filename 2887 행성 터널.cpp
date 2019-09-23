#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int par[100005];
int level[100005];

struct Edge{
	int a, b, c;
};

bool cmp(Edge e1, Edge e2){
	return e1.c < e2.c;
}

struct Planet{
	int x, y, z, number;
};

bool cmpX(Planet p1, Planet p2){
	return p1.x < p2.x;
}

bool cmpY(Planet p1, Planet p2){
	return p1.y < p2.y;
}

bool cmpZ(Planet p1, Planet p2){
	return p1.z < p2.z;
}

void init(){
	for(int i = 1 ; i < 100005 ; i++){
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
	int x, y, z;
	int cnt = 0, sum = 0, idx = 0;
	cin >> n;

	vector<Planet> temp;
	vector<Edge> v;

	init();
	
	for(int i = 1 ; i <= n ; i++){
		cin >> x >> y >> z;
		temp.push_back({x, y, z, i});
	}

	sort(temp.begin(), temp.end(), cmpX);
	for(int i = 0 ; i < n-1 ; i++){
		v.push_back({temp[i].number, temp[i+1].number, temp[i+1].x - temp[i].x});
	}
	sort(temp.begin(), temp.end(), cmpY);
	for(int i = 0 ; i < n-1 ; i++){
		v.push_back({temp[i].number, temp[i+1].number, temp[i+1].y - temp[i].y});
	}
	sort(temp.begin(), temp.end(), cmpZ);
	for(int i = 0 ; i < n-1 ; i++){
		v.push_back({temp[i].number, temp[i+1].number, temp[i+1].z - temp[i].z});
	}

	sort(v.begin(), v.end(), cmp);

	while(cnt != n-1){
		if(find(v[idx].a) != find(v[idx].b)){
			join(v[idx].a, v[idx].b);
			cnt++;
			sum += v[idx].c;
		}
		idx++;
	}

	cout << sum;
}