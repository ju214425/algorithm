#include <iostream>
#include <queue>

using namespace std;

struct Tomato{
	int x, y;
	int day;
};

int visit[1002][1002];
Tomato map[1002][1002];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
	int m, n, day = 0;
	Tomato f;
	cin >> m >> n;
	
	queue<Tomato> q;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			
			cin >> map[i][j];
			if(map[i][j] == 1){
				q.push({i, j, 0});
				visit[i][j] = 1;
			}
		}
	}

	while(!q.empty()){
		f = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			Tomato t = {f.x + dx[i], f.y + dy[i], f.day+1};
			if(0 <= t.x and t.x <= n and 0 <= t.y and t.y <= m){
				if(visit[t.x][t.y] == 0 and map[t.x][t.y] == 0){
					visit[t.x][t.y] = 1;
					map[t.x][t.y] = t.day;
					q.push(t);
				}
			}
		}
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(map[i][j] == 0){
				day = -1;
				break;
			}
			day = max(day, map[i][j]);
		}
	}

	cout << day;
}