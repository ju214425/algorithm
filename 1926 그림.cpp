#include <iostream>
#include <queue>

using namespace std;

int map[505][505];
int visit[505][505];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};


struct Coord{
	int x, y;
};

int bfs(int x, int y){
	int surf = 0;
	queue<Coord> q;
	q.push({x, y});
	visit[x][y] = 1;
	surf++;

	Coord f;
	while(!q.empty()){
		f = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			x = f.x + dx[i];
			y = f.y + dy[i];
			if(map[x][y] == 1 and visit[x][y] == 0){
				q.push({x, y});
				surf++;
				visit[x][y] = 1;
			}
		}
	}

	return surf;
}


int main(){
	int n, m;
	cin >> n >> m;

	queue<Coord> q;

	int surf = 0, cnt = 0;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> map[i][j];
		}
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(map[i][j] == 1 and visit[i][j] == 0){
				surf = max(surf, bfs(i, j));
				cnt++;
			}
		}
	}

	cout << cnt << "\n" << surf;
}