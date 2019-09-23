#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int map[102][102];
int visit[102][102];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = 1 ; i <= a ; i++){
		for(int j = 1 ; j <= b ; j++){
			scanf("%1d", &map[i][j]);
		}
	}

	queue<pair<int, int> > Q;
	pair<int, int> f;
	Q.push({1,1});
	visit[1][1] = 1;
	while(!Q.empty()){
		f = Q.front();
		Q.pop();
		if(f.first == a and f.second == b) break;
		for(int i = 0 ; i < 4 ; i++){
			pair<int, int> temp = {f.first + dx[i], f.second + dy[i]};
			if(1 <= temp.first and temp.first <= a and 1 <= temp.second and temp.second <= b){
				if(map[temp.first][temp.second] == 1 and visit[temp.first][temp.second] == 0){
					Q.push(temp);
					visit[temp.first][temp.second] = visit[f.first][f.second] + 1;
				}
			}
		}
	}

	printf("%d\n", visit[a][b]);
}