#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int country[55][55];
int par[2501];
int level[2501];
int child[2501];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void init(){
	for(int i = 1 ; i <= 2500 ; i++){
		par[i] = i;
		level[i] = 1;
		child[i] = 1;
	}
}

int find(int x){
	if(x == par[x])
		return;
	return par[x] = find(par[x]);
}

void join(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y)
		return;
	
	if(level[x] < level[y])
		swap(x, y);

	par[y] = x;
	int temp = child[x] + child[y];
	child[x] = child[y] = temp;
	if(level[x] == level[y])
		level[x]++;
}

int main(){
	int n, l, r;
	cin >> n >> l >> r;

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> country[i][j];
		}
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			pair<int, int> p = {i, j};
			for(int c = 0 ; c < 4 ; c++){
				pair<int, int> adj = {i + dx[c], j + dy[c]};
				if(0 < adj.first and adj.first <= n and 0 < adj.second and adj.second){
					if(abs(country[i][j] - country[adj.first][adj.second])){
						join(i * 50 + j, adj.first * 50 + adj.second);
					}
				}
			}
		}
	}


}