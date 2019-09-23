#include <iostream>

using namespace std;

int par[300005];
int level[300005];

void init(){
	for(int i = 0 ; i < 300005 ; i++){
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
		swap(x,y);

	par[x] = y;

	if(level[x] == level[y])
		level[y]++;
}

int main(){
	int n, q;
	int cmd, number;
	cin >> n >> q; 
	vector<string> ans(n);
	vector<pair<int, int> > quest(q+1);
	for(int i = 1 ; i <= n ; i++){

	}

	for(int i = 1 ; i <= q ; i++){
		cin >> q[i].first >> q[i].second;
	}

	for(int i = q ; i >= 1 ; i--){
		if(q[i].first == 1){
			
		}
		else{
			
		}
	}
}